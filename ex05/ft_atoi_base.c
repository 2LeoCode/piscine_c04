/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:10:33 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/12 14:42:48 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_nbr(char *str)
{
	int i;
	
	i = -1;
	while (str[++i]);
	if(str[0] == '-')
		return (i);
	else
		return (i + 1)
}

void	ft_negative(char *str, int *nbr, int *isneg)
{
	if (str[0] == '-')
		isneg
}

int		ft_atoi_base(char *str, char *base)
{
	int nb_int;
	int i;
	int j;

	i = ft_calc_base(base);
	j = ft_nbr(str);
	while (--j >= 0)
	{
		if (!(j == 0 && str[0] == '-'))
			{
				if ()
				nb_int += j * 10;	
			}
	}
	return (nb_int);
}
