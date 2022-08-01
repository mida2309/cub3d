/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_initialisation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:59:33 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 13:59:38 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_initialisation2(t_param *param)
{
	if (!(param->s.zbuffer = (double *)malloc(sizeof(double) * param->rx)))
		exit(0);
	param->data.forward = 0;
	param->data.back = 0;
	param->data.left = 0;
	param->data.right = 0;
	param->data.rotate_right = 0;
	param->data.rotate_left = 0;
	param->rayon.posx = (double)param->dx + 0.5;
	param->rayon.posy = (double)param->dy + 0.5;
	param->rayon.dirx = 0;
	param->rayon.diry = 0;
	param->rayon.planx = 0;
	param->rayon.plany = 0;
	ft_initialisation_direction(param);
}

void	ft_initialisation3(t_param *param)
{
	param->rayon.hit = 0;
	param->rayon.perpwalldist = 0;
	param->rayon.camerax = 2 * param->rayon.x / (double)param->rx - 1;
	param->rayon.rayondirx = param->rayon.dirx + param->rayon.planx * \
						param->rayon.camerax;
	param->rayon.rayondiry = param->rayon.diry + param->rayon.plany * \
						param->rayon.camerax;
	param->rayon.mapx = (int)param->rayon.posx;
	param->rayon.mapy = (int)param->rayon.posy;
	param->rayon.movespeed = 0.1;
	param->rayon.rotspeed = 0.033 * 1.8;
	ft_initialisation_more3(param);
}

void	ft_initialisation_texture(t_param *param)
{
	if (param->rayon.side == 0 && param->rayon.rayondirx < 0)
		param->t.texdir = 0;
	if (param->rayon.side == 0 && param->rayon.rayondirx >= 0)
		param->t.texdir = 1;
	if (param->rayon.side == 1 && param->rayon.rayondiry < 0)
		param->t.texdir = 2;
	if (param->rayon.side == 1 && param->rayon.rayondiry >= 0)
		param->t.texdir = 3;
	if (param->rayon.side == 0)
		param->t.wallx = param->rayon.posy + param->rayon.perpwalldist \
						* param->rayon.rayondiry;
	else
		param->t.wallx = param->rayon.posx + param->rayon.perpwalldist \
						* param->rayon.rayondirx;
	param->t.wallx -= floor((param->t.wallx));
}

void	ft_initialisation_sprite(t_param *param)
{
	int i;
	int j;

	i = -1;
	param->s.nbspr = 0;
	ft_verify_errors(param);
	while (++i < param->nblines)
	{
		j = -1;
		while (++j < param->sizeline)
		{
			if (param->map[i][j] == '2')
				param->s.nbspr += 1;
		}
	}
	if (!(param->sxy = (t_sprxy *)malloc(sizeof(t_sprxy) * param->s.nbspr)))
		ft_errors(param, "Malloc sxy*");
	if (!(param->s.order = (int *)malloc(sizeof(int) * param->s.nbspr)))
		ft_errors(param, "Malloc s.order*");
	if (!(param->s.dist = (double *)malloc(sizeof(double) * param->s.nbspr)))
		ft_errors(param, "Malloc s.dist*");
	ft_initialisation_sprite2(param, 0, 0, 0);
	ft_mlx(param);
}

void	ft_initialisation_sprite2(t_param *param, int i, int j, int v)
{
	i = i - 1;
	while (++i < param->nblines)
	{
		j = -1;
		while (++j < param->sizeline)
		{
			if (param->map[i][j] == '2')
			{
				param->sxy[v].x = (double)i + 0.5;
				param->sxy[v].y = (double)j + 0.5;
				v++;
			}
		}
	}
}
