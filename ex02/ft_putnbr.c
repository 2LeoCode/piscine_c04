/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:36:22 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/20 18:40:04 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnum(long i)
{
	char a;

	a = (char)i + 48;
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	long i;

	i = (long)nb;
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putnum(i);
}
