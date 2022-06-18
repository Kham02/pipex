#include "pipex_bonus.h"

void	error(char *s)
{
	return (perror(s));
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	t_all	all;

	if (ac < 3)
		error("Error: ./pipex infile ""\"cmd1\" \"cmd2\" ... \"cmdn\" outfile\n");
	get_path(&all, envp);
	open_fl(ac, av, &all);
	if (!ft_strcmp(av[1], "here_doc"))
		read_lim(av[2], &all);
	pars_cmd(av, &all);
	
}