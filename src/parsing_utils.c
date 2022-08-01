/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:58:50 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 13:58:55 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		ft_strlen2(char *str)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	while (str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int		ft_charingstr(char *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_depart(char c, t_param *param, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (param->dep != 'x')
			param->mulj = 1;
		param->dep = c;
		param->dx = i;
		param->dy = j;
		return (1);
	}
	return (0);
}

int		ft_wall_util(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	ft_initialisation(t_param *param)
{
	param->no = NULL;
	param->so = NULL;
	param->we = NULL;
	param->ea = NULL;
	param->sp = NULL;
	param->f = -1;
	param->c = -1;
	param->rx = 0;
	param->ry = 0;
	param->nblines = 0;
	param->sizeline = 0;
	param->map = NULL;
	param->dx = 0;
	param->dy = 0;
	param->mulj = 0;
	param->lignevide = 0;
	param->insidemap = 0;
	param->count = 0;
	param->sum = 0;
	param->wrongcharmap = 0;
	ft_initialisation_more(param);
}
