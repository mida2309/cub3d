/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:57:40 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 13:57:44 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		ft_key_press(int keycode, t_param *param)
{
	if (keycode == FORWARD_W_Z)
		param->data.forward = 1;
	else if (keycode == BACK_S_S)
		param->data.back = 1;
	else if (keycode == LEFT_A_Q)
		param->data.left = 1;
	else if (keycode == RIGHT_D_D)
		param->data.right = 1;
	else if (keycode == ROTATE_LEFT)
		param->data.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		param->data.rotate_right = 1;
	else if (keycode == 65307)
		ft_exit(param);
	return (1);
}

int		ft_key_release(int keycode, t_param *param)
{
	if (keycode == FORWARD_W_Z)
		param->data.forward = 0;
	else if (keycode == BACK_S_S)
		param->data.back = 0;
	else if (keycode == LEFT_A_Q)
		param->data.left = 0;
	else if (keycode == RIGHT_D_D)
		param->data.right = 0;
	else if (keycode == ROTATE_LEFT)
		param->data.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		param->data.rotate_right = 0;
	return (1);
}

int		ft_color_column(t_param *param)
{
	int j;
	int i;

	j = -1;
	param->rayon.drawend = param->ry - param->rayon.drawstart;
	i = param->rayon.drawend;
	while (++j < param->rayon.drawstart)
		param->data.addr[j * param->data.line_length / 4 +
			param->rayon.x] = param->c;
	if (j <= param->rayon.drawend)
		ft_draw_texture(param, param->rayon.x, j);
	j = i;
	while (++j < param->ry)
		param->data.addr[j * param->data.line_length / 4 +
			param->rayon.x] = param->f;
	return (0);
}

void	ft_draw_texture(t_param *param, int x, int y)
{
	y = param->rayon.drawstart - 1;
	ft_initialisation_texture(param);
	param->t.step = 1.0 * param->texture[0].height / param->rayon.lineheight;
	param->t.texx = (int)(param->t.wallx * (double)param->texture
			[param->t.texdir].width);
	if (param->rayon.side == 0 && param->rayon.rayondirx > 0)
		param->t.texx = param->texture[param->t.texdir].width -
			param->t.texx - 1;
	if (param->rayon.side == 1 && param->rayon.rayondiry < 0)
		param->t.texx = param->texture[param->t.texdir].width -
			param->t.texx - 1;
	param->t.texpos = (param->rayon.drawstart - param->ry / 2 +
			param->rayon.lineheight / 2) * param->t.step;
	while (++y <= param->rayon.drawend)
	{
		param->t.texy = (int)param->t.texpos &
			(param->texture[param->t.texdir].height - 1);
		param->t.texpos += param->t.step;
		if (y < param->ry && x < param->rx)
			param->data.addr[y * param->data.line_length / 4 + x] =
				param->texture[param->t.texdir].addr[param->t.texy *
					param->texture[param->t.texdir].line_length /
					4 + param->t.texx];
	}
}
