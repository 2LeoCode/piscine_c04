/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:36:22 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/17 16:00:48 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnum(int i)
{
	char a;

	a = (char)i + 48;
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	int i;
	int ng;
	
	ng = 0;
	i = nb;
	if (i < 0)
	{
		ng = 1;
		write(1, "-", 1);
		if (i == -2147483648)
			i = 2147483647;
		else
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
