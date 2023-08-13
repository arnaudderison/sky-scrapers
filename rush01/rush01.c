/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:45:24 by aderison          #+#    #+#             */
/*   Updated: 2023/08/13 09:27:54 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

#define N 4

char	ft_putnbr(int nb);
int		ft_chartoint(char *nb);
void	ft_putstr(char *str);
int		*ft_revtab(int *tab, int size);

int	check_visibility(int *tab, int visible)
{
	int	count;
	int	digit;
	int	i;

	count = 1;
	digit = tab[0];
	i = 1;
	while (i < N)
	{
		if (tab[i] > digit)
		{
			digit = tab[i];
			count++;
		}
		i++;
	}
	if (count == visible)
		return (1);
	return (0);
}

int	check_grid(int grid[N][N], int left[N], int right[N], int top[N],
		int bottom[N])
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	while (++i < N)
	{
		int row[N] = {0};
		int col[N] = {0};
		j = -1;
		while (++j < N)
		{
			row[j] = grid[i][j];
			col[j] = grid[j][i];
		}
		x = -1;
		while (++x < N)
		{
			y = x + 1;
			while (y < N)
			{
				if (row[x] == row[y] || col[x] == col[y])
					return (0);
				y++;
			}
		}
		if (!check_visibility(row, left[i]) || !check_visibility(ft_revtab(row,
					N), right[i]) || !check_visibility(col, top[i])
			|| !check_visibility(ft_revtab(col, N), bottom[i]))
			return (0);
	}
	return (1);
}

int	resolve(int tab[N][N], int x, int y, int left[N], int right[N], int top[N],
		int bottom[N])
{
	int	i;
	int	j;

	if (y == N)
		return (check_grid(tab, left, right, top, bottom));
	if (x == N)
		return (resolve(tab, 0, y + 1, left, right, top, bottom));
	i = 0;
	while (++i <= N)
	{
		tab[y][x] = i;
		if (resolve(tab, x + 1, y, left, right, top, bottom))
			return (1);
		tab[y][x] = 1;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = -1;
	j = -1;
	int grid[N][N] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
	int left[N] = {2, 1, 2, 3};
	int right[N] = {1, 2, 3, 2};
	int top[N] = {2, 2, 4, 1};
	int bottom[N] = {2, 2, 1, 4};

	// if (argc != 17)
	// {
	// 	ft_putstr("Please enter 16 digits");
	// 	return (0);
	// }
	resolve(grid, 0, 0, left, right, top, bottom);

	if (check_grid(grid, left, right, top, bottom))
	{
		while (++i < N)
		{
			j = -1;
			while (++j < N)
			{
				ft_putnbr(grid[i][j]);
			}
			ft_putstr("\n");
		}
	}
	else
	{
		ft_putstr("Aucune solution");
	}
	return (0);
}