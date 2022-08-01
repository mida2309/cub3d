/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:00:38 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 14:00:43 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_header(t_param *param, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * param->rx * param->ry;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &param->rx, 4);
	write(fd, &param->ry, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &param->data.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	ft_save(t_param *param)
{
	int	fd;
	int	x;
	int	y;

	y = param->ry;
	if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
		ft_errors(param, "Impossible de creer .bmp\n");
	ft_header(param, fd);
	while (y >= 0)
	{
		x = 0;
		while (x < param->rx)
		{
			write(fd, &param->data.addr[y * param->data.line_length / 4 + x],
				4);
			x++;
		}
		y--;
	}
	system("chmod 777 image.bmp");
	ft_exit(param);
}

int		ft_check_save(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'e' && str[i - 2] == 'v' && str[i - 3] == 'a' &&
		str[i - 4] == 's' && str[i - 5] == '-' && str[i - 6] == '-'
		&& ft_strlen(str) < 7)
		return (1);
	else
		return (0);
}

int		ft_nb_virgule(const char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			j++;
	}
	return (j);
}
