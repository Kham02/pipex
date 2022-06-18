#include "pipex_bonus.h"

void	read_lim(char *limit, t_all *all)
{
	char	*str;
	char	*lim;

	lim = malloc(sizeof(char) * ft_strlen(limit) + 2);
	ft_memmove(lim, str, ft_strlen(limit));
	lim[ft_strlen(limit)] = '\n';
	lim[ft_strlen[limit] + 1] = '\0';
	str = NULL;
	while (ft_strcmp(str, lim))
	{
		if (line)
			free(str);
		str = get_next_line(0, 1);
		if (!str)
			break;
		if (ft_strcmp(str, lim))
			write(all->cmd[0].in_fl, str, ft_strlen(str));
	}
	if (str)
		free(str);
	free(lim);
	close(all->cmd[0].in_fl);
}