#include "pipex_bonus.h"

void	write_var(int фc, char **av, t_all *all)
{
	all->ac = ac;
	all->count_cmd = ac - 3;
	all->count_st = 0;
	all->open_st = 0;
	if (!ft_strcmp(av[1], "here_doc"))
	{
		all->count_cmd--;
		all->open_st++;
	}
	if (all->count_cmd == 0)
	{
		all->count_cmd = 1;
		all->count_st = 1;
	}
	all->cmd = ft_calloc(sizeof(t_cmd), all->count_cmd);
	if (!all->cmd)
		error("Error: malloc\n")
}

void	open_fl(int fc, char **av, t_all *all)
{
	write_var(ac, av, all);
	if (!all->open_st)
	{
		all->cmd[0].in_fl = open(av[1], O_RDONLY);
		if (all->cmd[0].in_fl < 0)
			error(NULL);
		all->cmd[all->count_cmd - 1].out = open(av[all->ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	else
	{
		if (ft_strcmp("here_doc", av[all->ac - 1]))
			all->cmd[0].in_fl = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
		else
		{
			all->cmd[0].in_fl = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
			all->open_st++;
		}
		if (all->cmd[0].in_fl < 0)
			error(NULL);
		all->cmd[all->count_cmd - 1].out = open(av[all->ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	if (all->cmd[0].out_fl < 0)
		error(NULL);
}