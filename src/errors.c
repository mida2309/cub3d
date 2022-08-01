/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:56:28 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 13:56:34 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_verify_errors(t_param *param)
{
	if (ft_wall(param) == 1)
		ft_errors(param, "Map pas entouree de 1\n");
	if (param->dep == 'x')
		ft_errors(param, "Absence de joueur\n");
	if (param->indi2 != 6)
		ft_errors(param, "Erreur donnees F ou C\n");
	if (param->mulj == 1)
		ft_errors(param, "Trop de joueur\n");
	if (param->lignevide == 1)
		ft_errors(param, "Map avec ligne vide\n");
	if (param->wrongcharmap == 2)
		ft_errors(param, "Mauvais caractere dans la map\n");
}

void	ft_error2(t_param *param)
{
	if (param->map)
		free(param->map);
	if (param->s.order)
		free(param->s.order);
	if (param->s.dist)
		free(param->s.dist);
	if (param->sxy)
		free(param->sxy);
	if (param->s.zbuffer)
		free(param->s.zbuffer);
	ft_exit(param);
}

void	ft_errors(t_param *param, char *str)
{
	int i;

	i = -1;
	param->indi3 = 1;
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	if (param->no)
		free(param->no);
	if (param->so)
		free(param->so);
	if (param->we)
		free(param->we);
	if (param->ea)
		free(param->ea);
	if (param->sp)
		free(param->sp);
	if (param->map)
	{
		while (++i < param->nblines)
			free(param->map[i]);
	}
	ft_error2(param);
}

int		ft_exit(t_param *param)
{
	if (param->data.img)
		mlx_destroy_image(param->data.mlx_ptr, param->data.img);
	if (param->texture[0].img)
		mlx_destroy_image(param->data.mlx_ptr, param->texture[0].img);
	if (param->texture[1].img)
		mlx_destroy_image(param->data.mlx_ptr, param->texture[1].img);
	if (param->texture[2].img)
		mlx_destroy_image(param->data.mlx_ptr, param->texture[2].img);
	if (param->texture[3].img)
		mlx_destroy_image(param->data.mlx_ptr, param->texture[3].img);
	if (param->texture[4].img)
		mlx_destroy_image(param->data.mlx_ptr, param->texture[4].img);
	if (param->data.mlx_win)
		mlx_destroy_window(param->data.mlx_ptr, param->data.mlx_win);
	exit(0);
}
