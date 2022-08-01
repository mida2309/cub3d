/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idamouttou <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:57:54 by idamoutto         #+#    #+#             */
/*   Updated: 2021/01/28 13:57:59 by idamoutto        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int		ft_parsing_map(char *fichier, t_param *param)
{
	int			fd;
	int			ret;
	char		*str;

	ret = 1;
	str = NULL;
	fd = open(fichier, O_RDONLY);
	if (!(param->map = malloc(sizeof(char*) * param->nblines)))
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, param);
		if (param->insidemap == 1 && ft_lignevide(str) == 0 &&
				param->count < param->nblines)
			param->lignevide = 1;
		if ((param->insidemap = ft_is_map(str, param)) == 1)
		{
			param->count++;
			ft_copy_map(str, param);
		}
		free(str);
	}
	close(fd);
	ft_initialisation_sprite(param);
	return (0);
}

void	ft_parsing(char *fichier, t_param *param)
{
	int			fd;
	int			ret;
	char		*str;

	ret = 1;
	str = NULL;
	if ((fd = open(fichier, O_DIRECTORY)) != -1)
		ft_errors(param, "Error repertoire\n");
	if ((fd = open(fichier, O_RDONLY)) == -1)
		ft_errors(param, "Fichier .cub invalide\n");
	param->erreur = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, param);
		if (param->erreur == 2)
			ft_errors(param, "Parsing detecte une erreur\n");
		ft_color_resolution(&str, param);
		ft_texture(str, param);
		ft_map(str, param);
		free(str);
	}
	close(fd);
	if (param->sizeline == 0 || param->nblines == 0)
		ft_errors(param, "Map absente\n");
	ft_parsing_map(fichier, param);
}

int		ft_cub(char *str, t_param *param)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_errors(param, "Nom map invalide\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, param);
	else
		ft_errors(param, "Nom map invalide\n");
	return (0);
}

int		main(int argc, char **argv)
{
	t_param param;

	param.save = 0;
	ft_initialisation(&param);
	if (argc == 2 || (argc == 3 && ft_check_save(argv[2]) == 1))
	{
		if (argc == 3)
			param.save = 1;
		ft_cub(argv[1], &param);
	}
	else
		write(1, "Error\nArguments invalides\n", 27);
}
