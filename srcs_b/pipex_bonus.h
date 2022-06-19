#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* ~~~~~~~~~~~~ inc ~~~~~~~~~~~ */

# include "Libft/libft.h"

# include <unistd.h>
# include <stdio.h>
// #include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

/* ~~~~~~~~~~~~~ struct ~~~~~~~~~~~~~~ */

typedef struct s_cmd
{
	char	*cmd;
	int		in_fl;
	int		out_fl;
}t_cmd;

typedef struct s_all
{
	char	**path;
	t_cmd	*cmd;
	int		indx;
	int		open_st;
	int		count_st;
	int		count_cmd;
	pid_t	child;
	int		ac;
	int		end[2];
}t_all;

/* ~~~~~~~~~~~~~ fun ~~~~~~~~~~~~~~ */

void	error(char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	get_path(t_all *all, char **envp);
void	open_fl(int ac, char **av, t_all *all);
void	write_var(int ac, char **av, t_all *all);
void	read_lim(char *limit, t_all *all);
void	pars_cmd(char **av, t_all *all);
void	forks(int i, char **av, char **envp, t_all *all);

#endif