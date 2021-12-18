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

void error(char *s)
{
	return (perror(s));
	exit(EXIT_FAILURE);						// завершение работы с индикацией ошибки.
}

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

void	execution(char **argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(argv, ' ');
	execve(putch(argv, envp), cmd, envp);
}

void	path(char **cmd, char **envp)
{
	char	*pathh;
	char	**paths;
	char	*pat;
	int		i;		

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (ft_strnstr(envp[i], "PATH", 4) != 0)
		paths = ft_strdup(envp[i] + 5);
	i = 0;
	while (puth[i])
	{
		pat = ft_strjoin(paths[i], "/");
		pathh = ft_strjoin(pat, cmd);
		free(pat);
		if (access(path, F_OK) == 0)
				return (path);
		i++;
	}
	return (0);
}
