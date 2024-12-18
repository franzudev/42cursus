/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lincerpi <lincerpi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 20:04:55 by lincerpi          #+#    #+#             */
/*   Updated: 2021/06/14 20:18:27 by lincerpi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	error_env(char *arg)
{
	char	*env;

	g_sig.exit_status = 1;
	env = "HOME";
	if (arg && !ft_strncmp(arg, "-", 2))
		env = "OLDPWD";
	ft_putstr_fd("lsh: ", STDERR);
	ft_putstr_fd("cd", STDERR);
	ft_putstr_fd(": ", STDERR);
	ft_putstr_fd(env, STDERR);
	ft_putstr_fd(" not set", STDERR);
	ft_putstr_fd("\n", STDERR);
	return (1);
}

int	check_cdpath(char *str, t_env *env_lst)
{
	char	dirpath[BUF_SIZE];
	char	*tmp;
	char	*cdpath;
	int		len;

	len = 0;
	cdpath = get_env(env_lst, "CDPATH");
	ft_bzero(dirpath, BUF_SIZE);
	if (!cdpath || cdpath[0] == '\0')
		ft_strcat(dirpath, str);
	while (cdpath)
	{
		tmp = ft_strsep(&cdpath, ":");
		len = ft_strlen(tmp);
		ft_strlcpy(dirpath, tmp, len + 1);
		if (dirpath[len - 1] != '/')
			ft_strcat(dirpath, "/");
		ft_strcat(dirpath, str);
		if (file_exists(dirpath))
			break ;
	}
	return (chdir(dirpath));
}

char	*cd_set_path(char *arg, t_env *env_lst)
{
	char	*str;

	str = arg;
	if (!arg || !ft_strncmp(arg, "~", 2))
		str = get_env(env_lst, "HOME");
	else if (arg && !ft_strncmp(arg, "-", 2))
	{
		str = get_env(env_lst, "OLDPWD");
		if (str)
			ft_putendl_fd(str, STDOUT);
	}
	return (str);
}

int	change_directory(t_env *env_lst, char *str)
{
	int		ret;
	char	tmp[BUF_SIZE];

	ret = 0;
	ft_bzero(tmp, BUF_SIZE);
	if (str[0] != '\0')
	{
		if (file_exists(str))
			ret = chdir(str);
		else
		{
			ret = check_cdpath(str, env_lst);
			if (ret == 0)
			{
				getcwd(tmp, BUF_SIZE);
				ft_putendl_fd(tmp, STDOUT);
			}
		}
	}
	return (ret);
}

int	cd(char *arg, t_env *env_lst)
{
	int		errnum;
	int		ret;
	char	*str;
	char	tmp[BUF_SIZE];

	ret = 0;
	str = cd_set_path(arg, env_lst);
	ft_bzero(tmp, BUF_SIZE);
	if (str == NULL)
		return (error_env(arg));
	getcwd(tmp, BUF_SIZE);
	ret = change_directory(env_lst, str);
	errnum = errno;
	if (!ret)
		export_env(&env_lst, ft_strdup("OLDPWD"), ft_strdup(tmp));
	if (ret == 0)
		return (EXIT_SUCCESS);
	error_cases(errnum, "cd", str);
	return (EXIT_FAILURE);
}
