#include "pipex_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = -1;
	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
		return (1);
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return (1);
	return (0);
}

void	get_path(t_all *all, char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		error("Error: env not found\n");
	while (envp[i++] && ft_strncmp(*envp[i], "PATH", 4))
		;
	all->path = ft_split(*envp[i] + 5, ':');
	i = 0;
	while (all->path)
		all->path[i] = ft_strjoin(all->path[i], "/");
}