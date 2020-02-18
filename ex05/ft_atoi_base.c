/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:10:33 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/18 10:51:14 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int nb;
	int neg;

	i = 0;
	nb = 0;
	while (ft_isspace(str[i]))
		i++;
	i--;
	while (str[++i] == '+' || str[i] == '-')
		if (str[i] == '-')
			neg++;
	if (neg % 2 == 0)
		neg = -1;
	else
		neg = 1;
	i--;
	if (str[i] >= '0' && str[i] <= '9')
		nb = str[i] - 48;
	while (str[++i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - 48;
	}
	return (nb * neg);
}

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
	return(i);
}

void	ft_compare_string_base(char *string, char *base, int size)
{
	int i;
	int j;
	int k;

	k = 0;
	while (string[k])
		k++;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < k)
		{
			if (string[j] == base[i])
				string[j] = i + 48;
		}
	}
}

int		ft_atoi_base(char *str, char *base)
{
	int nb;
	int nb_fin;
	int bs;
	int i;
	int j;

	i = 0;
	bs = ft_calc_base(base);
	if (bs == 0)
		return (0);
	ft_compare_string_base(str, base, bs);
	nb = ft_atoi(str);
	while (str[i])
		i++;
	while (nb > 0)
	{
		j = i + 1;
		bs = ft_calc_base(base);
		while (--j > 0)
			bs *= bs;
		nb_fin *= 10;
		nb_fin += nb % bs;
		nb /= 10;
	}	
	return (nb_fin);
}
