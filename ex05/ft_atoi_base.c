/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:10:33 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/22 14:04:59 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SIZE	tab[128]

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
		if (b[i] == '+' || b[i] == '-' || b[i] == ' ')
			return (0);
	}
	if (i < 2)
		return (0);
	return (i);
}

void	*ft_compare_string_base(char *string, char *base, int size, int *tab)
{
	int		i;
	int		k;
	int		ok;

	k = 0;
	ok = 0;
	while (string[k])
	{
		ok = 0;
		i = -1;
		while (base[++i])
			if (string[k] == base[i])
				ok = 1;
		if (ok == 0)
			break ;
		k++;
	}
	SIZE = k;
	i = -1;
	while (++i < SIZE)
	{
		k = -1;
		while (++k < size)
			if (string[i] == base[k])
				tab[i] = k;
	}
	return (tab);
}

int		ft_pow(int nb, int pow)
{
	if (pow < 0)
		return (nb);
	if (pow > 0)
		return (nb * ft_pow(nb, pow - 1));
	return (1);
}

int		ft_get_nb(int *tab, int base)
{
	int i;
	int j;
	int nb;

	nb = 0;
	j = 0;
	i = SIZE - 1;
	j = 0;
	while (j < SIZE)
	{
		nb += tab[i] * ft_pow(base, j);
		i--;
		j++;
	}
	return (nb);
}

int		ft_atoi_base(char *str, char *base)
{
	int	neg;
	int nb_fin;
	int	bs;
	int tab[129];
	int i;

	i = 0;
	neg = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	str = &str[i];
	nb_fin = 0;
	bs = ft_calc_base(base);
	if (bs == 0)
		return (0);
	ft_compare_string_base(str, base, bs, tab);
	nb_fin = ft_get_nb(tab, bs) * neg;
	return (nb_fin);
}
