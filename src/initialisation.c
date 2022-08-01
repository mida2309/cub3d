/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:57:16 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 13:57:22 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_initialisation_more(t_param *param)
{
	param->dep = 'x';
	param->indi2 = 0;
	param->indi3 = 0;
	param->data.img = NULL;
	param->texture[0].img = NULL;
	param->texture[1].img = NULL;
	param->texture[2].img = NULL;
	param->texture[3].img = NULL;
	param->texture[4].img = NULL;
	param->data.mlx_win = NULL;
	param->map = NULL;
	param->s.order = NULL;
	param->s.dist = NULL;
	param->s.zbuffer = NULL;
	param->sxy = NULL;
}

void	ft_initialisation_direction(t_param *param)
{
	if (param->dep == 'N')
		param->rayon.dirx = -1;
	if (param->dep == 'S')
		param->rayon.dirx = 1;
	if (param->dep == 'E')
		param->rayon.diry = 1;
	if (param->dep == 'W')
		param->rayon.diry = -1;
	if (param->dep == 'N')
		param->rayon.plany = 0.66;
	if (param->dep == 'S')
		param->rayon.plany = -0.66;
	if (param->dep == 'E')
		param->rayon.planx = 0.66;
	if (param->dep == 'W')
		param->rayon.planx = -0.66;
}

void	ft_initialisation_more3(t_param *param)
{
	if (param->rayon.rayondiry == 0)
		param->rayon.deltadistx = 0;
	else if (param->rayon.rayondirx == 0)
		param->rayon.deltadistx = 1;
	else
		param->rayon.deltadistx = sqrt(1 + (param->rayon.rayondiry
			* param->rayon.rayondiry) / (param->rayon.rayondirx *
			param->rayon.rayondirx));
	if (param->rayon.rayondirx == 0)
		param->rayon.deltadisty = 0;
	else if (param->rayon.rayondiry == 0)
		param->rayon.deltadisty = 1;
	else
		param->rayon.deltadisty = sqrt(1 + (param->rayon.rayondirx *
			param->rayon.rayondirx) / (param->rayon.rayondiry *
			param->rayon.rayondiry));
}

void	ft_atoi3_check(const char *str, t_param *param)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != ',')
		i++;
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while ((str[i] < '0' || str[i] > '9') && str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		param->erreur = 2;
	if (ft_nb_virgule(str) != 2)
		param->erreur = 2;
}

int		ft_lignevide(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0' &&
				str[i] != '\n' && str[i] != '\r' && str[i] != '\v'
				&& str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}
