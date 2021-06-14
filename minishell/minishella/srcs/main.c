/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:10:48 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:27:23 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_sig	g_sig;

void	init_msh(t_state **st, t_env **env_lst, char **envp)
{
	int		lvl;
	char	*tmp;
	char	buf[BUF_SIZE];
	char	*key;

	(*st)->in = dup(STDIN);
	(*st)->out = dup(STDOUT);
	lvl = 1;
	tmp = NULL;
	ft_bzero(buf, BUF_SIZE);
	init_fds(st);
	sig_init(NULL);
	init_env(env_lst, envp);
	tmp = get_env(*env_lst, "SHLVL");
	if (tmp != NULL)
	{
		lvl = ft_atoi(tmp);
		lvl++;
	}
	tmp = ft_itoa(lvl);
	key = ft_strdup("SHLVL");
	export_env(env_lst, key, tmp);
	printf("Welcome to LilloShell!\n");
}

int	get_input(t_state *st, char *input)
{
	char	*line;

	line = ft_readlinev2(st, "Lillo ❯ ");
	if (line == NULL)
		return (0);
	ft_strlcpy(input, line, ft_strlen(line));
	free(line);
	return (1);
}

void	main_loop(t_state *st, t_env *env_lst, t_cmd *cmd_lst)
{
	char	input[BUF_SIZE];
	char	*env;

	while (1)
	{
		enable_raw_mode(st);
		ft_bzero(input, BUF_SIZE);
		catch_signal();
		get_input(st, input);
		if (!is_empty(input))
		{
			hist_update(&st->history, input);
			env = concat_env(env_lst);
			st->envp = ft_split(env, '\n');
			free(env);
			disable_raw_mode(st);
			parse_cmdline(st, &env_lst, cmd_lst, input);
			free_2darray(st->envp);
			g_sig.sigint = 0;
			g_sig.sigquit = 0;
			g_sig.pid = 0;
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env_lst;
	t_cmd	*cmd_lst;
	t_state	*st;

	(void)argv;
	env_lst = NULL;
	cmd_lst = NULL;
	st = NULL;
	if (argc < 2)
	{
		st = ft_calloc(1, sizeof(t_state));
		init_msh(&st, &env_lst, envp);
		main_loop(st, env_lst, cmd_lst);
	}
	else
		printf("Usage: just ./minishell with no arguments.\n");
	return (EXIT_SUCCESS);
}
