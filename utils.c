/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:23:25 by estrong           #+#    #+#             */
/*   Updated: 2022/03/06 11:41:56 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void error(char *s)
{
	return (perror(s));
	exit(EXIT_FAILURE);						// завершение работы с индикацией ошибки.
}

void	free2arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	execution(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	path = paths(cmd, envp);
	if (!path)
	{
		free2arr(cmd);
		error("path not found");
	}
	execve(path, cmd, envp);
}

char	*paths(char **cmd, char **envp)
{
	char	**paths;
	char	*pathh;
	char	*path;
	int		i;

	i = 0;
	path = ft_strdup("");
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
		free(path);
		i++;
	}
	free2arr(paths);
	return (0);
}
