/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 20:12:19 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/17 19:42:47 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_calc_base(char *b)
{
	int i;
	int j;

	i = -1;
	while (b[++i])
	{
		j = -1;
		while (b[++j])
			if (i != j && b[i] == b[j])
				return (0);
		if (b[i] == '+' || b[i] == '-')
			return (0);
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	nb;

	i = ft_calc_base(base);
	if (i == 0)
		return ;
	nb = (long)nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	{
		if (nb >= ft_calc_base(base))
		{
			ft_putnbr_base(nb / i, base);
			ft_putnbr_base(nb % i, base);
		}
		else
			write(1, &base[nb], 1);
	}
}
