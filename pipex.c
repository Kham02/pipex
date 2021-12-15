/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:08:03 by estrong           #+#    #+#             */
/*   Updated: 2021/12/13 16:14:12 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1_process(int fd1, int *end, char **argv, char **envp)
{
	dup2(end[1], STDOUT_FILENO) < 0;
	dup2(fd1, STDIN_FILENO) < 0;
	close(end[0]);							// закрываем конец канала
	close(end[1]);
	close(fd1);								// закрываем файл
	execution(argv[2], envp);
}

static void	child2_process(int fd1, int *end, char **argv, char **envp)
{
	dup2(end[0], STDOUT_FILENO) < 0;
	dup2(fd1, STDIN_FILENO) < 0;
	close(end[1]);
	close(end[0]);
	close(fd1);
	execution(argv[3], envp);
}

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int	end[2];
	pid_t child1;								//тип данных - целое число со знаком, который способен представить ID процесса.
	pid_t child2;

	if (pipe(end) == -1)						// создание канала
		error("pipe: ");
	child1 = fork();							// делим процесс на два подпроцесса
	if (child1 < 0)								// в случае ошибки fork вернет -1
		error("fork: ");
	if (child1 == 0)							// возвращает 0, если мы находимся в дочернем процессе
		child1_process(fd1, end, argv, envp);
	child2 = fork();
	if (child2 < 0)
		error("fork: ");
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
	fd2 = open("infile.txt", O_RDWR, O_TRUNC);
	if (fd1 < 0 || fd2 < 0)
		return (-1);
	pipex(fd1, fd2, argv, envp);
	return (0);
}
