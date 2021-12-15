/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 23:44:31 by estrong           #+#    #+#             */
/*   Updated: 2021/12/13 16:14:26 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

void	pipex(int fd1, int fd2, char **argv, char **envp);
int		get_next_line(char **line);
void	execution(char **argv, char **envp);
void	path(int fd2, char **argv, char **envp);
void error(char *s);


#endif