/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:23:25 by estrong           #+#    #+#             */
/*   Updated: 2022/01/17 18:48:36 by estrong          ###   ########.fr       */
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
	char	*paths;
	char	*pat;
	int		i;		

	i = 0;
	paths = ft_strdup("");
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (ft_strnstr(envp[i], "PATH", 4) != 0)
		paths = ft_strdup((envp[i] + 5));
	i = 0;
	while (paths[i])
	{
		pat = ft_strjoin(&paths[i], "/");
		pathh = ft_strjoin(pat, *cmd);
		free(pat);
		if (access(pathh, F_OK) == 0)
			return(pathh);
		else
			error("access: ");
		
		i++;
	}
	exit(EXIT_FAILURE);
}
