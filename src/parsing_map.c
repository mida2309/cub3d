/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:58:31 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 13:58:36 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		ft_wall(t_param *param)
{
	int i;

	i = 0;
	while (i < param->nblines)
	{
		if (param->map[i][0] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < param->nblines)
	{
		if (param->map[i][param->sizeline - 1] != '1')
			return (1);
		i++;
	}
	if (ft_wall_util(param->map[0]) == 1)
		return (1);
	if (ft_wall_util(param->map[param->nblines - 1]) == 1)
		return (1);
	return (0);
}

int		ft_copy_map(char *str, t_param *param)
{
	static int	i = 0;
	int			j;

	j = 0;
	param->map[i] = NULL;
	if (!(param->map[i] = malloc(sizeof(char) * param->sizeline + 1)))
		return (0);
	while (str[j] != '\0')
	{
		if (ft_depart(str[j], param, i, j) == 1)
			param->map[i][j] = '0';
		else if (str[j] == ' ')
			param->map[i][j] = '1';
		else
			param->map[i][j] = str[j];
		j++;
	}
	while (j <= (param->sizeline - 1))
	{
		param->map[i][j] = '1';
		j++;
	}
	param->map[i][j] = '\0';
	i++;
	return (0);
}

int		ft_is_map(char *str, t_param *param)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charingstr(str, '1') == 1 || ft_charingstr(str, '0') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1' \
					&& str[i] != '2' && str[i] != 'N' && str[i] != 'S' \
					&& str[i] != 'E' && str[i] != 'W' && str[i] != '\n'
					&& str[i] != '\t')
			{
				if (param->insidemap == 1)
					param->wrongcharmap = 2;
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

void	ft_map(char *str, t_param *param)
{
	int			i;
	static int	snblines = 0;
	static int	ssizeline = 0;

	i = 0;
	if (ft_is_map(str, param) == 1)
	{
		if (param->f == -1 || param->c == -1 || param->no == NULL ||
				param->so == NULL || param->we == NULL ||
				param->ea == NULL || param->sp == NULL)
			param->erreur = 2;
		if ((i = ft_strlen(str)) > ssizeline)
			ssizeline = i;
		snblines = snblines + 1;
	}
	param->nblines = snblines;
	param->sizeline = ssizeline;
}
