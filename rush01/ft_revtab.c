/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 07:21:44 by aderison          #+#    #+#             */
/*   Updated: 2023/08/13 07:32:50 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_revtab(int *tab, int size)
{
	int i;
	int j;
	int tmp;

	i = size - 1;
	j = 0;
	while (i > j)
	{
		tmp = tab[j];
		tab[j] = tab[i];
		tab[i] = tmp;
		i--;
		j++;
	}
	return (tab);
}