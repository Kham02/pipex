/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estrong <estrong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 23:44:31 by estrong           #+#    #+#             */
/*   Updated: 2022/03/06 11:44:02 by estrong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "Libft/libft.h"

#include <unistd.h>
#include <stdio.h>
// #include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int		main(int argc, char **argv, char **envp);
void	pipex(char **argv, char **envp);
void	execution(char *argv, char **envp);
char	*paths(char **argv, char **envp);
void 	error(char *s);
void	free2arr(char **arr);

#endif
