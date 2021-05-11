#include "../../minishell.h"

static void	ft_set_pwd(void)
{
	t_list *t;
	t_list *new;
	char	*cwd;
	char	buff[MAX_LEN];
	int	flag;

	flag = 0;
	t = term->env;
	while(t)
	{
		if (ft_strncmp(((t_env *)t->content)->name, "PWD", 3) == 0)
		{
			cwd = getcwd(buff, MAX_LEN);
			((t_env *)t->content)->value = cwd;
			flag = 1;
			break ;
		}
		t = t->next;
	}
	if(!flag)
	{
		((t_env *)new->content)->name = "PWD";
		((t_env *)new->content)->value = cwd;
		ft_lstadd_back(&t, new);
	}
}
static void ft_set_old_pwd(char *old_pwd)
{
	t_list *t;
	t_list *new;
	int	flag;

	flag = 0;
	t = term->env;
	while(t)
	{
		if (ft_strncmp(((t_env *)t->content)->name, "OLD_PWD", 7) == 0)
		{
			((t_env *)t->content)->value = old_pwd;
			flag = 1;
			break ;
		}
		t = t->next;
	}
	if(!flag)
	{
		((t_env *)new->content)->name = "OLD_PWD";
		((t_env *)new->content)->value = old_pwd;
		ft_lstadd_back(&t, new);
	}
}

static int	ft_change_dir(char *path)
{
	char	*cwd;
	char	buff[MAX_LEN];

	cwd = getcwd(buff, MAX_LEN);
	if (!chdir(path))
	{
		ft_set_old_pwd(cwd);
		ft_set_pwd();
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	cmd_cd(t_comm *cmd)
{
	char *home;
	t_list	*t;

	t = term->env;
	while(t)
	{
		if (ft_strncmp(((t_env *)t->content)->name, "HOME", 4) == 0)
		{
			home = ((t_env *)t->content)->value;
			break;
		}
		t = t->next;
	}
	if (!cmd->args)
		return (ft_change_dir(home));
	return (ft_change_dir(cmd->args));
}
