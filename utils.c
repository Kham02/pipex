/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:23:25 by estrong           #+#    #+#             */
/*   Updated: 2021/12/13 16:11:37 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_next_line(char **line)
{
	int	i;
	int	count_read;

	i = 0;
	*line = (char *)malloc(1000);
	if (!*line)
		return (-1);
	while ((count_read = read(0, *line + i, 1)) > 0)
	{
		if ((*line)[i] == '\n')
			break ;
		i++;
	}
	(*line)[i] = '\0';
	return (count_read);
}

void	execution(char *puth, char **argv, char **envp)
{
	
}