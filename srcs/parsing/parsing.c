/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:19:57 by lboiteux          #+#    #+#             */
/*   Updated: 2024/06/13 20:01:14 by lboiteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}

char	**format_tab(char **tab, int height)
{
	int		i;
	int		j;
	char	**new_tab;

	new_tab = ft_calloc(height + 1, sizeof(char *));
	i = -1;
	while (tab[++i])
	{
		new_tab[i] = ft_calloc(ft_strlen(tab[i]) + 1, sizeof(char));
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == '\n')
				new_tab[i][j] = '\0';
			else if (ft_iswhitespace(tab[i][j]))
				new_tab[i][j] = '1';
			else
				new_tab[i][j] = tab[i][j];
		}
	}
	ft_free_tab(tab);
	return (new_tab);
}

int	is_wall_texture(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] != 'g' || str[len - 2] != 'n' || str[len - 3] != 'p' || str[len - 4] != '.')
		return (-1);
	if (str[0] == 'W' && str[1] == 'E')
		return (0);
	if (str[0] == 'N' && str[1] == 'O')
		return (1);
	if (str[0] == 'S' && str[1] == 'O')
		return (2);
	if (str[0] == 'E' && str[1] == 'A')
		return (3);
	return (-1);
}

void	get_wall_texture(t_cube *cube, t_map *map, int fd)
{
	char	*str;
	int		i;
	char	*texture_path;

	i = 0;
	str = get_next_line(fd, 0);
	map->west_texture = NULL;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	while (i < 4)
	{
		if (str && ft_strlen(str) > 7 && is_wall_texture(str))
		{
			texture_path = ft_strdup(str + 2);
			if (is_wall_texture(str) == 0)
				map->west_texture = mlx_png_file_to_image(cube->mlx_ptr, texture_path, NULL, NULL);
			if (is_wall_texture(str) == 1)
				map->north_texture = mlx_png_file_to_image(cube->mlx_ptr, texture_path, NULL, NULL);
			if (is_wall_texture(str) == 2)
				map->south_texture = mlx_png_file_to_image(cube->mlx_ptr, texture_path, NULL, NULL);
			if (is_wall_texture(str) == 3)
				map->east_texture = mlx_png_file_to_image(cube->mlx_ptr, texture_path, NULL, NULL);
		}
		else
		{
			ft_dprintf(2, "Error\nTexture path is not valid\n");
			free(str);
			return ;
		}
		free(texture_path);
		free(str);
		i++;
		str = get_next_line(fd, 0);
	}
	if (!(map->west_texture && map->north_texture && map->south_texture && map->east_texture))
	{
		ft_dprintf(2, "Error\nTexture path is not valid or one texture is missing\n");
		return ;
	}
}

int	check_colors(char **colors)
{
	int	i;
	int	j;

	i = -1;
	while (colors[++i])
	{
		j = -1;
		while (colors[i][++j])
		{
			if (!ft_isdigit(colors[i][j]) || ft_strlen(colors[i]) > 3)
			{
				ft_printf("colors[%d] = %s\n", i, colors[i]);
				ft_printf("ft_strlen(colors[%d]) = %d\n", i, ft_strlen(colors[i]));
				ft_dprintf(2, "Error\n4Color is not valid\n");
				return (0);
			}
		}
	}
	return (1);

}

unsigned long	convert_rgb_to_hexa(char **colors)
{
	int				r;
	int				g;
	int				b;
	unsigned long	color;

	if (!check_colors(colors))
		return (0);
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		ft_dprintf(2, "Error\n1Color is not valid\n");
		ft_free_tab(colors);
		return (0);
	}
	color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	ft_free_tab(colors);
	return (color);
}

void	get_colors(t_map *map, int fd)
{
	char			**colors;
	char			*str;
	unsigned long	color;

	str = get_next_line(fd, 0);
	if (!str || (str[0] != 'C' && str[0] != 'F') || str[1] != ' ')
	{
		ft_dprintf(2, "Error\n2Color is not valid\n");
		free(str);
	}
	colors = ft_str_split(str + 2, "\n,");
	if (!colors || ft_tablen(colors) != 3)
	{
		ft_printf("%d\n", ft_tablen(colors));
		ft_dprintf(2, "Error\n3Color is not valid\n");
		ft_free_tab(colors);
		free(str);
	}
	color = convert_rgb_to_hexa(colors);
	if (str[0] == 'C')
		map->ceiling_color = color;
	if (str[0] == 'F')
		map->floor_color = color;
	free(str);
}

char	**read_map(t_cube *cube, t_map *map, char *file)
{
	int		i;
	int		fd;
	char	**tab;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	tab = ft_calloc(map->height + 1, sizeof(char *));
	get_wall_texture(cube, map, fd);
	get_colors(map, fd);
	get_colors(map, fd);
	i = -1;
	while (++i < 3)
	{
		tab[0] = get_next_line(fd, 0);
		free(tab[0]);
	}
	i = 0;
	tab[i] = get_next_line(fd, 0);
	if (!tab[i])
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	while (tab[i])
	{
		i++;
		tab[i] = get_next_line(fd, 0);
	}
	return (tab);
}

void	parsing(t_cube *cube, t_map *map, char *file)
{
	char	**tab;

	tab = read_map(cube, map, file);
	if (!tab)
		return ;
	tab = format_tab(tab, map->height);
	print_tab(tab);
	map->map = tab;
}
