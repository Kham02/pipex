/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:08:03 by estrong           #+#    #+#             */
/*   Updated: 2021/12/12 00:10:21 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1_process(int fd1, char *cmd1, char *end[1])
{
	dup2(fd1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);							// закрываем конец канала
	close(fd1);								// закрываем файл
	exit (EXIT_FAILURE);					// выход из путей
}

static void	pars(int fd2, char *cmd2, char *end[0])
{
	char	*PATH_from_envp;
	char	**mypaths;
	char	**mycmdargs;
	int		i;
	char	*cmd;

	i = -1;
	PATH_from_envp = ft_substr(envp ....);
	mypaths = ft_split(PATH_from_envp, ":");
	while (mypaths[++i])
{
	cmd = ft_join(mypaths[i], ag[2]);
	execve(cmd, mycmdargs, envp);
	free(cmd);
}
return (EXIT_FAILURE);
}

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int	end[2];
	int	status;
	pid_t child1;							//тип данных - целое число со знаком, который способен представить ID процесса.
	pid_t parent;

	pipe(end);								// создание канала
	child1 = fork();						// делим процесс на два подпроцесса
	parent = fork();
	if (child1 < 0 || child2 < 0)			// в случае ошибки fork вернет -1
		return (perror("Fork: "));
	if (child1 == 0)						// возвращает 0, если мы находимся в дочернем процессе
		child1_process(f1, cmd1, end[1]);
	if (parent == 0)
	{
		waitid(child1, &status, 0);				// родитель ждет завершения дочерних процессов
		dup2(fd2, STDIN_FILENO);
		dup2(end[0], STDOUT_FILENO);
		close(end[1]);
		exit (EXIT_FAILURE);
	}
}

int main	(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (argc != 5)
		return (0);
	fd1 = open("outfile.txt", O_RDWR);
	fd2 = open("infile.txt", O_RDWR);
	if (fd1 < 0 || fd2 < 0)
		return (-1);
	pipex(f1, f2, argv, envp);
	return (0);
}
