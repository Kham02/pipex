#include "pipex_bonus.h"

static int	opn_fl(int i, char **av, t_all *all)
{
	if (all->open_st)
	{
		if (all->open_st == 1)
			all->cmd[0].in_fl = open(av[1], O_RDONLY);
		else
			all->cmd[0].in_fl = open("her_doc", O_RDONLY);
		i += 1;
	}
}

void	pars_cmd(char **av, t_all *all)
{
	int	i;

	i = 1;
	all->indx = 0;
	i = opn_fl(i, av, &all);
	while (++all->indx < all->count_cmd)
	{
		pipe(all->end);
		all->cmd[all->indx - 1].cmd = ft_split(av[i + 1], ' ');
		if (!all->cmd[all->indx - 1].cmd)
			error("Error: malloc\n");
		all->cmd[all->indx - 1].out_fl = all->end[1];
		all->cmd[all->indx].in_fl = all->end[0];
	}
	if (all->count_st)
		all->cmd[all->indx - 1].cmd = ft_split("cat", ' ');
	else
		all->cmd[all->indx - 1].cmd = ft_split(av[i + 1], ' ');
	if (!all->cmd[all->indx - 1].cmd || all->cmd[0].in_fl < 0)
		error("Error: malloc");
}