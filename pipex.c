/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:08:03 by estrong           #+#    #+#             */
/*   Updated: 2021/12/13 10:13:30 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1_process(int fd1, int *end, char **argv, char **envp)
{
	if (dup2(end[1], STDOUT_FILENO) < 0)
		return (perror("infile: "));
	if (dup2(fd1, STDIN_FILENO) < 0)
		return (perror(""));
	close(end[0]);							// закрываем конец канала
	close(end[1]);
	close(fd1);								// закрываем файл
	
}

static void	child2_process(int fd1, int *end, char **argv, char **envp)
{
	if (dup2(end[0], STDOUT_FILENO) < 0)
		return (perror("outfile: "));
	if (dup2(fd1, STDIN_FILENO) < 0)
		return (perror(""));
	close(end[1]);
	close(end[0]);
	close(fd1);
	
}

// static void	pars(int fd2, char **argv, char **envp)
// {
// 	char	*PATH_from_envp;
// 	char	**mypaths;
// 	char	**mycmdargs;
// 	int		i;
// 	char	*cmd;

// 	i = -1;
// 	PATH_from_envp = ft_substr(envp ....);
// 	mypaths = ft_split(PATH_from_envp, ":");
// 	while (mypaths[++i])
// {
// 	cmd = ft_join(mypaths[i], ag[2]);
// 	execve(cmd, mycmdargs, envp);
// 	free(cmd);
// }
// return (EXIT_FAILURE);
// }

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int	end[2];
	pid_t child1;							//тип данных - целое число со знаком, который способен представить ID процесса.
	pid_t child2;

	pipe(end);								// создание канала
	child1 = fork();						// делим процесс на два подпроцесса
	if (child1 < 0)							// в случае ошибки fork вернет -1
		return (perror("Fork: "));
	if (child1 == 0)						// возвращает 0, если мы находимся в дочернем процессе
		child1_process(fd1, end, argv, envp);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		child2_process(fd2, end, argv, envp);
	close(end[0]);
	close(end[1]);
	waitid(child1, NULL, 0);
	waitid(child2, NULL, 0);
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
	pipex(fd1, fd2, argv, envp);
	return (0);
}
