#include "pipex_bonus.h"

void	error(char *s)
{
	return (perror(s));
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_all	all;
	int		i;

	i = 0;
	if (ac < 3)
		error("Error: ./pipex infile ""\"cmd1\" \"cmd2\" ... \"cmdn\" outfile\n");
	get_path(&all, envp);
	open_fl(ac, av, &all);
	if (!ft_strcmp(av[1], "here_doc"))
		read_lim(av[2], &all);
	pars_cmd(av, &all);
	while (i++ < all.count_cmd)
		forks(i, envp, &all);
	while (i--)
		wait(NULL);
	if (all.open_st == 1)
		unlink("here_doc");
	else if (all.open_st == 2)
		unlink("her_doc");
	return (0);
}