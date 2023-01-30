/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouaza <mbouaza@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:37:37 by mbouaza           #+#    #+#             */
/*   Updated: 2022/12/23 06:27:30 by mbouaza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* just for copy a string of my map */

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dest;

	len = ft_strlen(s1);
	i = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* to free any char * and my char ** of my map_copy */

char	**free_all(char **map, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(map[j]);
		j++;
	}
	free(map);
	return (NULL);
}

/* just for check a char for my map */

int	check_char(char word, char c)
{
	if (word == c)
		return (1);
	else
		return (-1);
}

/* error message if my check is false */

int	error_message(int num_of_error)
{
	if (num_of_error == 0)
		ft_printf("Error\nThe map isn't rectangular!\n");
	else if (num_of_error == 1)
		ft_printf("Error\nThe map isn't surrounded by wall!\n");
	else if (num_of_error == 2)
		ft_printf("Error\nThe file isn't a .ber!\n");
	else if (num_of_error == 3)
		ft_printf("Error\nCheck your map, we have more or less item!\n");
	else if (num_of_error == 4)
		ft_printf("Error\nThe map isn't possible!\n");
	else if (num_of_error == 5)
		ft_printf("Error\nThe map failed to be copied!\n");
	else if (num_of_error == 6)
		ft_printf("Error\nThe map have an unknown letter/number in the map!\n");
	else if (num_of_error == 7)
		ft_printf("Error\nThe map can't be open!\n");
	exit(EXIT_FAILURE);
}

char	*ft_s(char const *s1, char const *s2)
{
	int		len;
	int		len2;
	char	*newstr;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	len2 = 0;
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (0);
	len = 0;
	while (s1[len2])
		newstr[len++] = s1[len2++];
	len2 = 0;
	while (s2[len2])
		newstr[len++] = s2[len2++];
	newstr[len] = '\0';
	return (newstr);
}
