/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:08:03 by estrong           #+#    #+#             */
/*   Updated: 2022/01/19 17:40:38 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1_process(int *end, char **argv, char **envp)
{
	int	fd1;

	fd1 = open(argv[1],  O_RDONLY);
	if (fd1 < 0)
		error("open file: ");
	dup2(fd1, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);							// закрываем конец канала
	close(fd1);
	execution(&argv[2], envp);
}

static void	child2_process(int *end, char **argv, char **envp)
{
	int	fd2;

	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd2 < 0)
		error("open file: ");
	dup2(fd2, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(fd2);
	execution(&argv[3], envp);
}

void	pipex(char **argv, char **envp)
{
	int		end[2];
	pid_t	child1;								//тип данных - целое число со знаком, который способен представить ID процесса.
	pid_t	child2;

	pipe(end);									// создание канала
	child1 = fork();							// делим процесс на два подпроцесса
	if (child1 < 0)								// в случае ошибки fork вернет -1
		error("fork: ");
	if (child1 == 0)										// возвращает 0, если мы находимся в дочернем процессе
		child1_process(end, argv, envp);
	child2 = fork();
	if (child2 < 0)
		error("fork: ");
	if (child2 == 0)
		child2_process(end, argv, envp);
	close(end[0]);
	close(end[1]);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
}

int main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (0);
	pipex(argv, envp);
	return(0);
}
