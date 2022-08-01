/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:01:02 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 14:01:06 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_dist_order2(t_param *param)
{
	int i;

	i = -1;
	while (++i < param->s.nbspr)
	{
		param->s.order[i] = i;
		param->s.dist[i] = ((param->rayon.posx - param->sxy[i].x) *
				(param->rayon.posx - param->sxy[i].x) + (param->rayon.posy -
					param->sxy[i].y) * (param->rayon.posy - param->sxy[i].y));
	}
}

void	ft_dist_order(t_param *param)
{
	int		i;
	int		j;
	double	tmp;

	ft_dist_order2(param);
	i = -1;
	while (++i < param->s.nbspr)
	{
		j = -1;
		while (++j < param->s.nbspr - 1)
		{
			if (param->s.dist[j] < param->s.dist[j + 1])
			{
				tmp = param->s.dist[j];
				param->s.dist[j] = param->s.dist[j + 1];
				param->s.dist[j + 1] = tmp;
				tmp = param->s.order[j];
				param->s.order[j] = param->s.order[j + 1];
				param->s.order[j + 1] = (int)tmp;
			}
		}
	}
}

void	ft_calculs(t_param *param, int i)
{
	param->s.spritex = param->sxy[param->s.order[i]].x - param->rayon.posx;
	param->s.spritey = param->sxy[param->s.order[i]].y - param->rayon.posy;
	param->s.invdet = 1.0 / (param->rayon.planx * param->rayon.diry -
			param->rayon.dirx * param->rayon.plany);
	param->s.transformx = param->s.invdet * (param->rayon.diry *
			param->s.spritex - param->rayon.dirx * param->s.spritey);
	param->s.transformy = param->s.invdet * (-param->rayon.plany *
			param->s.spritex + param->rayon.planx * param->s.spritey);
	param->s.spritescreenx = (int)((param->rx / 2) * (1 + param->s.transformx
				/ param->s.transformy));
	param->s.spriteheight = abs((int)(param->ry / (param->s.transformy)));
	param->s.drawstarty = -param->s.spriteheight / 2 + param->ry / 2;
	if (param->s.drawstarty < 0)
		param->s.drawstarty = 0;
	param->s.drawendy = param->s.spriteheight / 2 + param->ry / 2;
	if (param->s.drawendy >= param->ry)
		param->s.drawendy = param->ry;
	param->s.spritewidth = abs((int)(param->ry / (param->s.transformy)));
	param->s.drawstartx = -param->s.spritewidth / 2 + param->s.spritescreenx;
	if (param->s.drawstartx < 0)
		param->s.drawstartx = 0;
	param->s.drawendx = param->s.spritewidth / 2 + param->s.spritescreenx;
	if (param->s.drawendx >= param->rx)
		param->s.drawendx = param->rx;
}

void	ft_draw_spr(t_param *param, int y, int texx, int stripe)
{
	int		d;
	int		texy;

	while (y < param->s.drawendy)
	{
		d = (y) * 256 - param->ry * 128 + param->s.spriteheight * 128;
		texy = ((d * param->texture[4].height) / param->s.spriteheight) / 256;
		if (param->texture[4].addr[texy * param->texture[4].line_length / 4 +
				texx] != -16777216)
		{
			param->data.addr[y * param->data.line_length / 4 + stripe] =
				param->texture[4].addr[texy * param->texture[4].line_length /
				4 + texx];
		}
		y++;
	}
}

void	ft_sprite(t_param *param)
{
	int i;
	int y;
	int stripe;
	int texx;

	i = -1;
	ft_dist_order(param);
	while (++i < param->s.nbspr)
	{
		ft_calculs(param, i);
		stripe = param->s.drawstartx;
		while (stripe < param->s.drawendx)
		{
			texx = (int)(256 * (stripe - (-param->s.spritewidth / 2 +
							param->s.spritescreenx)) * param->texture[4].width
					/ param->s.spritewidth) / 256;
			if (param->s.transformy > 0 && stripe >= 0 && stripe < param->rx
					&& param->s.transformy < param->s.zbuffer[stripe])
			{
				y = param->s.drawstarty;
				ft_draw_spr(param, y, texx, stripe);
			}
			stripe++;
		}
	}
}
