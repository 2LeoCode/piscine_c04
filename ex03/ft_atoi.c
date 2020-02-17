/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:57:57 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/17 12:59:11 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

int		ft_negative(char *str, int *k)
{
	int n;

	*k = *k - 1;
	n = 0;

	while (str[++*k] == '-' || str[*k] == '+')
		if (str[*k] == '-')
			n++;
	if (n % 2 != 0)
		return (-1);
	return (1);
}

int		ft_recurs_atoi(int init, int end, char *str, int *nb)
{
	int i;
	int j;

	i = init;
	j = end;
	if (!str[i] || i == j)
		return (*nb);
	else
	{
		*nb *= 10;
		*nb += str[i] - 48;
		return(ft_recurs_atoi(i + 1, j, str, nb));
	}
}

int		ft_atoi(char *str)
{
	int i;
	int j;
	int nb;
	int ng;

	i = 0;
	nb = 0;
	while (ft_isspace(str[i]))
		i++;
	ng = ft_negative(str, &i);
	j = i - 1;
	while (str[++j] >= '0' && str[j] <= '9')
		continue;
	ft_recurs_atoi(i, j, str, &nb);
	return (nb * ng);
}
