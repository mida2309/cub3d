/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:00:06 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 14:00:23 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_stepsidedist(t_param *param)
{
	if (param->rayon.rayondirx < 0)
	{
		param->rayon.stepx = -1;
		param->rayon.sidedistx = (param->rayon.posx - param->rayon.mapx) \
							* param->rayon.deltadistx;
	}
	else
	{
		param->rayon.stepx = 1;
		param->rayon.sidedistx = (param->rayon.mapx + 1.0 - param->rayon.posx) \
							* param->rayon.deltadistx;
	}
	if (param->rayon.rayondiry < 0)
	{
		param->rayon.stepy = -1;
		param->rayon.sidedisty = (param->rayon.posy - param->rayon.mapy) \
							* param->rayon.deltadisty;
	}
	else
	{
		param->rayon.stepy = 1;
		param->rayon.sidedisty = (param->rayon.mapy + 1.0 - param->rayon.posy) \
							* param->rayon.deltadisty;
	}
	ft_incrementrayon(param);
}

void	ft_incrementrayon(t_param *param)
{
	while (param->rayon.hit == 0)
	{
		if (param->rayon.sidedistx < param->rayon.sidedisty)
		{
			param->rayon.sidedistx += param->rayon.deltadistx;
			param->rayon.mapx += param->rayon.stepx;
			param->rayon.side = 0;
		}
		else
		{
			param->rayon.sidedisty += param->rayon.deltadisty;
			param->rayon.mapy += param->rayon.stepy;
			param->rayon.side = 1;
		}
		if (param->map[param->rayon.mapx][param->rayon.mapy] == '1')
			param->rayon.hit = 1;
	}
	ft_drawstartend(param);
}

void	ft_drawstartend(t_param *param)
{
	if (param->rayon.side == 0)
		param->rayon.perpwalldist = ((double)param->rayon.mapx - \
				param->rayon.posx + (1 - (double)param->rayon.
				stepx) / 2) / param->rayon.rayondirx;
	else
		param->rayon.perpwalldist = ((double)param->rayon.mapy - \
				param->rayon.posy + (1 - (double)param->rayon.
				stepy) / 2) / param->rayon.rayondiry;
	param->rayon.lineheight = (int)(param->ry / param->rayon.perpwalldist);
	param->rayon.drawstart = -param->rayon.lineheight / 2 + param->ry / 2;
	if (param->rayon.drawstart < 0)
		param->rayon.drawstart = 0;
	param->rayon.drawend = param->rayon.lineheight / 2 + param->ry / 2;
	if (param->rayon.drawend >= param->ry || param->rayon.drawend < 0)
		param->rayon.drawend = param->ry - 1;
}

void	ft_swap(t_param *param)
{
	void *tmp;

	tmp = param->data.img;
	param->data.img = param->data.img2;
	param->data.img2 = tmp;
	tmp = param->data.addr;
	param->data.addr = param->data.addr2;
	param->data.addr2 = tmp;
}
