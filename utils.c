/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:23:25 by estrong           #+#    #+#             */
/*   Updated: 2022/01/19 15:08:34 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error(char *s)
{
	return (perror(s));
	exit(EXIT_FAILURE);						// завершение работы с индикацией ошибки.
}

void	execution(char **argv, char **envp)
{
	char	**cmd;

	cmd = ft_split(*argv, ' ');
	execve(path(argv, envp), cmd, envp);
}

char	*path(char **cmd, char **envp)
{
	char	*pathh;
	char	**paths;
	char	*path;
	int		i;		

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		pathh = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path, *cmd);
		free(pathh);
		if (access(path, F_OK) == 0)
			return(path);
		i++;
	}
	return (0);
}
