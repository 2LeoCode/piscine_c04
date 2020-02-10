/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:36:22 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/10 16:41:11 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_nbchiffres(int i)
{
	int n;

	n = 0;
	while (i != 0)
	{
		i /= 10;
		n++;
	}
	return (n);
}

int		ft_is_negative(int i)
{
	int j;

	if (i < 0)
	{
		j = -1;
	}
	else
	{
		j = 1;
	}
	return (j);
}

void	ft_print_ng(int i)
{
	if (i < 0)
	{
		write(1, "-", 1);
	}
}

void	ft_putnbr(int nb)
{
	int		cpt;
	int		index;
	char	tab_ch[10];

	cpt = ft_nbchiffres(nb);
	index = 1;
	ft_print_ng(nb);
	while (cpt > 1)
	{
		index *= 10;
		cpt--;
	}
	cpt = 0;
	while (index > 0)
	{
		tab_ch[cpt] = (char)(nb / index * ft_is_negative(nb)) + 48;
		write(1, &tab_ch[cpt], 1);
		nb %= index;
		index /= 10;
		cpt++;
	}
}
