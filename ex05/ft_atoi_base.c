/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:10:33 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/17 23:01:58 by lsuardi          ###   ########.fr       */
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
		if (b[i] == '+' || b[i] == '-' || b[i] = ' ')
			return (0);
	}
	if (i < 2)
		return (0);
	return(i);
}

void	ft_compare_string_base(char *string, char *base)
{
	int i;
	int j;

	i = -1;
	while (base[++i])
	{
		j = -1;
		while (string[++j])
			if (string[j] == base[i])
				string[j] = i + 48;
	}
}

int		ft_atoi_base(char *str, char *base)
{
	int nb;
	int bs;
	int j;

	bs = ft_calc_base(base);
	if (bs == 0)
		return (0);
	ft_compare_string_base(str, base);
	while ()	
	return (nb_int);
}
