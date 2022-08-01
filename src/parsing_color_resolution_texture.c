/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color_resolution_texture.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:58:11 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 13:58:20 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		ft_atoi2(const char *str, t_param *param)
{
	int		sum;

	sum = 0;
	if (str[1] != ' ' || ft_charingstr((char *)str, ',') == 1)
		param->erreur = 2;
	while (str[param->i] == ' ' || str[param->i] == '\t'
			|| str[param->i] == ',' || str[param->i] == '\n'
			|| str[param->i] == '\r' || str[param->i] == '\v'
			|| str[param->i] == '\f')
		param->i++;
	if (str[param->i] == '-' || str[param->i] == '+')
		param->erreur = 2;
	while (str[param->i] >= '0' && str[param->i] <= '9')
	{
		if (sum > 21474636)
			break ;
		sum = (sum * 10) + (str[param->i] - 48);
		param->i++;
	}
	while (str[param->i] >= '0' && str[param->i] <= '9')
		param->i++;
	return (sum);
}

int		ft_atoi3(const char *str, t_param *param)
{
	int		verify;

	verify = 0;
	if (str[1] != ' ')
		param->erreur = 2;
	ft_atoi3_check(str, param);
	while (str[param->i] == ' ' || str[param->i] == '\t' || str[param->i]
			== ',' || str[param->i] == '\n' || str[param->i] == '\r'
			|| str[param->i] == '\v' || str[param->i] == '\f')
	{
		param->i++;
		verify = 0;
		if (str[param->i] >= '0' && str[param->i] <= '9')
			param->indi2++;
		while (str[param->i] >= '0' && str[param->i] <= '9')
		{
			verify = (verify * 10) + str[param->i] - 48;
			param->sum = (param->sum * 10) + (str[param->i] - 48);
			param->i++;
		}
		if (verify > 255 || verify < 0)
			param->erreur = 2;
	}
	return (param->sum);
}

int		ft_p_texture(char *str, char **texture, t_param *param, int j)
{
	param->count2 = 0;
	if (*texture != NULL)
	{
		param->erreur = 2;
		return (0);
	}
	if (ft_charingstr(str, '.') == 0 || ft_charingstr(str, '/') == 0
			|| ft_strlen2(str) <= 2)
		param->erreur = 2;
	while (str[j] != '.')
	{
		if (str[j] != ' ' && str[j] != '.')
			param->erreur = 2;
		j++;
	}
	if (!(*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(str) + 1)))))
		param->erreur = 2;
	while (str[j] != '\0')
	{
		(*texture)[param->count2] = str[j];
		param->count2++;
		j++;
	}
	(*texture)[param->count2] = '\0';
	return (0);
}

void	ft_texture(char *str, t_param *param)
{
	int			i;
	static int	j = 0;

	i = 0;
	if (str[i] == 'S' && str[i + 1] == 'O')
		ft_p_texture(str, &param->no, param, 2);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		ft_p_texture(str, &param->so, param, 2);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_p_texture(str, &param->we, param, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_p_texture(str, &param->ea, param, 2);
	else if (str[i] == 'S' && str[i + 1] != 'O')
		ft_p_texture(str, &param->sp, param, 1);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
			&& str[0] != 'R' && str[0] != 'F' && str[0] != 'C'
			&& str[0] > 65 && str[0] < 122)
		param->erreur = 2;
	j++;
}

void	ft_color_resolution(char **str, t_param *param)
{
	int			i;

	i = 0;
	param->i = 1;
	if (param->sizeline > 0 && (param->no == NULL || param->so == NULL ||
				param->we == NULL || param->ea == NULL || param->sp == NULL))
		param->erreur = 2;
	if ((param->no != NULL || param->so != NULL || param->we != NULL ||
				param->ea != NULL || param->sp != NULL) && (param->rx == 0
				|| param->ry == 0))
		param->erreur = 2;
	if (*str[i] == 'R')
	{
		if (param->rx != 0 && param->ry != 0)
			param->erreur = 2;
		param->rx = ft_atoi2(*str, param);
		param->ry = ft_atoi2(*str, param);
		if (ft_atoi2(*str, param) > 0 || param->rx == 0 || param->ry == 0)
			param->erreur = 2;
	}
	else if (*str[i] == 'F')
		param->f = ft_atoi3(*str, param);
	else if (*str[i] == 'C')
		param->c = ft_atoi3(*str, param);
}
