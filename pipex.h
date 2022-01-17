/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 23:44:31 by estrong           #+#    #+#             */
/*   Updated: 2022/01/17 18:46:37 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/libft.h"

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

int		main(int argc, char **argv, char **envp);
void	pipex(int fd1, int fd2, char **argv, char **envp);
void	execution(char **argv, char **envp);
char	*path(char **argv, char **envp);
void 	error(char *s);

#endif
