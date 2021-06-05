#include "../../minishell.h"

static void	ft_set_pwd(void)
{
	t_list	*t;
	char	*cwd;
	char	buff[MAX_LEN];

	t = term->env;
	cwd = getcwd(buff, MAX_LEN);
	while (t)
	{
		if (!ft_strncmp(((t_env *)t->content)->name, "PWD", 3))
			((t_env *)t->content)->value = cwd;
		t = t->next;
	}
}

static void	ft_set_old_pwd(char *old_pwd)
{
	t_list	*t;

	t = term->env;
	while (t)
	{
		if (ft_strncmp(((t_env *)t->content)->name, "OLDPWD", 6) == 0)
			((t_env *)t->content)->value = old_pwd;
		t = t->next;
	}
}

static int	ft_change_dir(char *path)
{
	char	buff[MAX_LEN];
	char	*cwd;

	cwd = getcwd(buff, MAX_LEN);
	if (!chdir(path))
	{
		ft_set_old_pwd(cwd);
		ft_set_pwd();
		return (EXIT_SUCCESS);
	}
	write(1, "cd: ", 4);
	write(1, path, ft_strlen(path));
	write(1, ": No such file or directory\n\x0d", 29);
	return (EXIT_FAILURE);
}

int	cmd_cd(t_comm *cmd)
{
	char	*home;
	t_list	*t;
	char	*temp;

	t = term->env;
	while (t)
	{
		if (ft_strncmp(((t_env *)t->content)->name, "HOME", 4) == 0)
		{
			home = ((t_env *)t->content)->value;
			break ;
		}
		t = t->next;
	}
	if (cmd->args[1] && cmd->args[1][0] == '~')
	{
		temp = ft_strjoin(home, cmd->args[1] + 1);
		free(cmd->args[1]);
		cmd->args[1] = ft_strdup(temp);
		free(temp);
	}
	if (!cmd->args[1])
		return (ft_change_dir(home));
	return (ft_change_dir(cmd->args[1]));
}
