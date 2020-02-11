/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:47:59 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/11 20:04:13 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_count
{
	int less;
	int nb;
	int check;
}				t_count;

void	ft_init_compteur(t_count *c)
{
	(*c).less = 0;
	(*c).nb = 0;
	(*c).check = 0;
}

void	ft_travail(char *str, t_count *c, int i)
{
	if (str[i] >= 48 && str[i] <= 57)
	{
		(*c).check = 1;
		i--;
	}
	while ((*c).check == 1)
	{
		while (str[++i] >= 48 && str[i] <= 57)
		{
			(*c).nb += str[i] - 48;
			if (str[i + 1] >= 48 && str[i + 1] <= 57)
				(*c).nb *= 10;
			else
			{
				(*c).check = 0;
				break ;
			}
		}
	}
}

int		ft_check_negative(t_count *c)
{
	if ((*c).less % 2 == 0)
		return (1);
	else
		return(-1);
}	

int		ft_atoi(char *str)
{
	int 	i;
	t_count	compteur;

	i = -1;
	ft_init_compteur(&compteur);
	while (str[++i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			compteur.less++;
	}
	i--;
	while (str[++i])
	{
		ft_travail(str, &compteur, i);
		break;
	} 
	return(compteur.nb * ft_check_negative(&compteur));
}
