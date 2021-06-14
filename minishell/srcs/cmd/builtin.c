#include "../../minishell.h"

static void	free_path(char **dir_path)
{
	int	i;

	i = -1;
	while (dir_path[++i])
		free(dir_path[i]);
	free(dir_path);
	dir_path = NULL;
}

char	**ft_dir_path(void)
{
	t_list	*t;
	char	**dir_path;
	int		i;
	char	*temp;

	dir_path = NULL;
	t = g_term->env;
	while (t)
	{
		if (!ft_strncmp(((t_env *)t->content)->name, "PATH", 4))
		{
			dir_path = ft_split(((t_env *)t->content)->value, ':');
			i = 0;
			while (dir_path[i])
			{
				temp = ft_strjoin(dir_path[i], "/");
				free(dir_path[i]);
				dir_path[i] = ft_strdup(temp);
				free (temp);
				i++;
			}
			break ;
		}
		t = t->next;
	}
	return (dir_path);
}

char	*ft_full_path(char **dir_path, char *cmd)
{
	char	*full_path;
	int		i;
	void	*stat;

	stat = malloc(sizeof(struct stat));
	if (!stat)
		return (NULL);
	i = 0;
	full_path = NULL;
	while (dir_path[i])
	{
		full_path = ft_strjoin(dir_path[i], cmd);
		if (!lstat(full_path, stat))
		{
			free(stat);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free(stat);
	return (NULL);
}

int	cmd_bin(t_comm *cmd)
{
	char	*full_path;
	char	**dir_path;
	void	*stat;

	stat = malloc(sizeof(struct stat));
	if (!stat)
		return (EXIT_FAILURE);
	if (!lstat(cmd->value, stat))
	{
		free(stat);
		full_path = cmd->value;
	}
	else
	{
		dir_path = ft_dir_path();
		full_path = ft_full_path(dir_path, cmd->value);
		free_path(dir_path);
	}
	if (full_path)
	{
		execve(full_path, cmd->args, g_term->reenv);
		g_term->last_status_code = 0;
		return (EXIT_SUCCESS);
	}
	// g_term->last_status_code = errno;
	// ft_putnbr_fd(g_term->last_status_code, 1);
	return (EXIT_FAILURE);
}
