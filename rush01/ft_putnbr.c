/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderison <aderison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:49:03 by aderison          #+#    #+#             */
/*   Updated: 2023/08/13 07:22:48 by aderison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	ft_putnbr(int nb)
{
	char n;

	if (nb <= 9 && nb >= 1)
	{
		n = nb + '0';
		write(1, &n, 1);
	}
	return (0);
}