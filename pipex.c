/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:08:03 by estrong           #+#    #+#             */
/*   Updated: 2021/12/11 21:50:49 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1_process(int fd, char *cmd)
{

}

static void	child2_process(int fd, char *cmd)
{
	
}

void	pipex(int f1, int f2, char *cmd1, char *cmd2)
{
	int	end[2];
	int	status;
	pid_t child1;						//тип данных - целое число со знаком, который способен представить ID процесса.
	pid_t child2;

	pipe(end);							// создание канала
	child1 = fork();					// делим процесс на два подпроцесса
	if (child1 < 0)						// в случае ошибки fork вернет -1
		return (perror("Fork: "));
	if (child1 == 0)					// возвращает 0, если мы находимся в дочернем процессе
		child1_process(f1, cmd1);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		child2_process(f2, cmd2);
	close(end[0]);
	close(end[1]);
	waitid(child1, &status, 0);			// родитель ждет завершения дочерних процессов
	waitid(child2, &status, 0);
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
	dup2(fd1, 1);
	dup2(fd2, 0);
	printf("%s", env);
	// pipex(f1, f2, argv, envp);
	return (0);
}