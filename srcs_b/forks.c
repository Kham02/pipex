#include "pipex_bonus.h"

static void	close_fd(int i, int status, t_all *all)
{
	if (!status)
	{
		while (i--)
		{
			close(all->cmd[1].in_fl);
			close(all->cmd[1].out_fl);
		}
	}
	else
	{
		close(all->cmd[1].in_fl);
		close(all->cmd[1].out_fl);
	}
}

static void	pth(char *act_cmd, char **cmd, t_all *all)
{
	int	i;

	i = 0;
	while (all->path[i++])
	{
		if (!act_cmd)
			break;
		*cmd = ft_strjoin(all->path[i], act_cmd);
		if (!*cmd)
			error("Error: malloc\n");
		if (!access(*cmd, F_OK))
			return ;
		free (*cmd);
	}
	*cmd = NULL;
	if (!all->path[i] || !act_cmd)
		error("Error: no such cmd\n");
}

static void	execute_cmd(char **cmd, char **envp, t_all *all)
{
	char	*cmd_path;

	pth(cmd[0], &cmd_path, all);
	execve(cmd_path, cmd, envp);
	free(cmd_path);
	exit(99);
}

static void	child_pr(int i, char **envp, t_all *all)
{
	if (dup2(all->cmd[i].in_fl, STDIN_FILENO) < 0 
		|| dup2(all->cmd[i].out_fl, STDOUT_FILENO) < 0)
		error("Error: dup2\n");
	close_fd(i, 0, all);
	execute_cmd(all->cmd[i].cmd, envp);
}

void	forks(int i, char **av, t_all *all)
{
	all->child = fork();
	if (all->child < 0)
		error("Error: fork\n");
	if (!all->child)
		child_pr(i, envp, all);
	close_fd(i, 1, all);
}