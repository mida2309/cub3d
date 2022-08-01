/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:59:50 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 14:47:21 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_forward_back(t_param *param)
{
	if (param->data.forward == 1)
	{
		if (param->map[(int)(param->rayon.posx + (param->rayon.dirx * param->
						rayon.movespeed * 2))][(int)param->rayon.posy] == '0')
			param->rayon.posx += param->rayon.dirx * param->rayon.movespeed;
		if (param->map[(int)(param->rayon.posx)][(int)(param->rayon.posy +
					(param->rayon.diry * param->rayon.movespeed * 2))] == '0')
			param->rayon.posy += param->rayon.diry * param->rayon.movespeed;
	}
	if (param->data.back == 1)
	{
		if (param->map[(int)(param->rayon.posx - (param->rayon.dirx * param->
						rayon.movespeed * 2))][(int)(param->rayon.posy)] == '0')
			param->rayon.posx -= param->rayon.dirx * param->rayon.movespeed;
		if (param->map[(int)(param->rayon.posx)][(int)(param->rayon.posy -
					(param->rayon.diry * param->rayon.movespeed * 2))] == '0')
			param->rayon.posy -= param->rayon.diry * param->rayon.movespeed;
	}
}

void	ft_left_right(t_param *param)
{
	if (param->data.right == 1)
	{
		if (param->map[(int)(param->rayon.posx + param->rayon.diry *
					(param->rayon.movespeed * 2))][(int)param->
					rayon.posy] == '0')
			param->rayon.posx += param->rayon.diry * param->rayon.movespeed;
		if (param->map[(int)param->rayon.posx][(int)(param->rayon.posy -
					param->rayon.dirx *
					(param->rayon.movespeed * 2))] == '0')
			param->rayon.posy -= param->rayon.dirx * param->rayon.movespeed;
	}
	if (param->data.left == 1)
	{
		if (param->map[(int)(param->rayon.posx - param->rayon.diry *
					(param->rayon.movespeed * 2))][(int)param->
					rayon.posy] == '0')
			param->rayon.posx -= param->rayon.diry * param->rayon.movespeed;
		if (param->map[(int)param->rayon.posx][(int)(param->rayon.posy +
					param->rayon.dirx *
					(param->rayon.movespeed * 2))] == '0')
			param->rayon.posy += param->rayon.dirx * param->rayon.movespeed;
	}
}

void	ft_rotate_right_left(t_param *param)
{
	double oldplanx;
	double olddirx;

	oldplanx = param->rayon.planx;
	olddirx = param->rayon.dirx;
	if (param->data.rotate_right == 1)
	{
		param->rayon.dirx = param->rayon.dirx * cos(-param->
							rayon.rotspeed / 2) -
			param->rayon.diry * sin(-param->rayon.rotspeed / 2);
		param->rayon.diry = olddirx * sin(-param->rayon.rotspeed / 2) +
			param->rayon.diry * cos(-param->rayon.rotspeed / 2);
		param->rayon.planx = param->rayon.planx * cos(-param->
							rayon.rotspeed / 2)
			- param->rayon.plany * sin(-param->rayon.rotspeed / 2);
		param->rayon.plany = oldplanx * sin(-param->rayon.rotspeed / 2) +
			param->rayon.plany * cos(-param->rayon.rotspeed / 2);
	}
	ft_rotate_left(param, olddirx);
}

void	ft_rotate_left(t_param *param, double olddirx)
{
	double oldplanex;

	if (param->data.rotate_left == 1)
	{
		olddirx = param->rayon.dirx;
		oldplanex = param->rayon.planx;
		param->rayon.dirx = param->rayon.dirx * cos(param->rayon.rotspeed / 2) -
			param->rayon.diry * sin(param->rayon.rotspeed / 2);
		param->rayon.diry = olddirx * sin(param->rayon.rotspeed / 2) + param->
			rayon.diry * cos(param->rayon.rotspeed / 2);
		param->rayon.planx = param->rayon.planx * cos(param->
								rayon.rotspeed / 2) -
			param->rayon.plany * sin(param->rayon.rotspeed / 2);
		param->rayon.plany = oldplanex * sin(param->rayon.rotspeed / 2) +
			param->rayon.plany * cos(param->rayon.rotspeed / 2);
	}
}
