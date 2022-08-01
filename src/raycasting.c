/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:59:14 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 13:59:19 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_get_texture_adress(t_param *param)
{
	param->texture[0].addr = (int *)mlx_get_data_addr(param->texture[0].img,
			&param->texture[0].bits_per_pixel,
			&param->texture[0].line_length, &param->texture[0].endian);
	param->texture[1].addr = (int *)mlx_get_data_addr(param->texture[1].img,
			&param->texture[1].bits_per_pixel,
			&param->texture[1].line_length, &param->texture[1].endian);
	param->texture[2].addr = (int *)mlx_get_data_addr(param->texture[2].img,
			&param->texture[2].bits_per_pixel,
			&param->texture[2].line_length, &param->texture[2].endian);
	param->texture[3].addr = (int *)mlx_get_data_addr(param->texture[3].img,
			&param->texture[3].bits_per_pixel,
			&param->texture[3].line_length, &param->texture[3].endian);
	param->texture[4].addr = (int *)mlx_get_data_addr(param->texture[4].img,
			&param->texture[4].bits_per_pixel,
			&param->texture[4].line_length, &param->texture[4].endian);
}

void	ft_get_texture(t_param *param)
{
	if (!(param->texture[0].img = mlx_xpm_file_to_image(param->data.mlx_ptr,
					param->no, &(param->texture[0].width),
					&(param->texture[0].height))))
		ft_errors(param, "Texture SO\n");
	if (!(param->texture[1].img = mlx_xpm_file_to_image(param->data.mlx_ptr,
					param->so, &(param->texture[1].width),
					&(param->texture[1].height))))
		ft_errors(param, "Texture NO\n");
	if (!(param->texture[2].img = mlx_xpm_file_to_image(param->data.mlx_ptr,
					param->we, &(param->texture[2].width),
					&(param->texture[2].height))))
		ft_errors(param, "Texture EA\n");
	if (!(param->texture[3].img = mlx_xpm_file_to_image(param->data.mlx_ptr,
					param->ea, &(param->texture[3].width),
					&(param->texture[3].height))))
		ft_errors(param, "Texture WE\n");
	if (!(param->texture[4].img = mlx_xpm_file_to_image(param->data.mlx_ptr,
					param->sp, &(param->texture[4].width),
					&(param->texture[4].height))))
		ft_errors(param, "Texture S\n");
	ft_get_texture_adress(param);
}

int		ft_raycasting(t_param *param)
{
	param->rayon.x = 0;
	while (param->rayon.x < param->rx)
	{
		ft_initialisation3(param);
		ft_stepsidedist(param);
		ft_color_column(param);
		param->s.zbuffer[param->rayon.x] = param->rayon.perpwalldist;
		param->rayon.x++;
	}
	ft_sprite(param);
	if (param->save == 1)
		ft_save(param);
	mlx_put_image_to_window(param->data.mlx_ptr, param->data.mlx_win,
			param->data.img, 0, 0);
	ft_forward_back(param);
	ft_left_right(param);
	ft_rotate_right_left(param);
	ft_swap(param);
	return (0);
}

int		ft_mlx(t_param *param)
{
	ft_initialisation2(param);
	if (!(param->data.mlx_ptr = mlx_init()))
		ft_errors(param, "Mlx initialisation impossible\n");
	mlx_get_screen_size(param->data.mlx_ptr, &param->screenx, &param->screeny);
	param->rx = (param->rx > param->screenx) ? param->screenx : param->rx;
	param->ry = (param->ry > param->screeny) ? param->screeny : param->ry;
	ft_get_texture(param);
	param->data.img = mlx_new_image(param->data.mlx_ptr, param->rx, param->ry);
	param->data.addr = (int *)mlx_get_data_addr(param->data.img, &param->data.
			bits_per_pixel, &param->data.line_length, &param->data.endian);
	if (param->save == 1)
		ft_raycasting(param);
	param->data.mlx_win = mlx_new_window(param->data.mlx_ptr, param->rx,
			param->ry, "Cub3D mida");
	param->data.img2 = mlx_new_image(param->data.mlx_ptr, param->rx, param->ry);
	param->data.addr2 = (int *)mlx_get_data_addr(param->data.img2, &param->
			data.bits_per_pixel, &param->data.line_length, &param->data.endian);
	mlx_hook(param->data.mlx_win, 33, 1L << 17, ft_exit, param);
	mlx_hook(param->data.mlx_win, 2, 1L << 0, ft_key_press, param);
	mlx_loop_hook(param->data.mlx_ptr, ft_raycasting, param);
	mlx_hook(param->data.mlx_win, 3, 1L << 1, ft_key_release, param);
	mlx_loop(param->data.mlx_ptr);
	return (0);
}
