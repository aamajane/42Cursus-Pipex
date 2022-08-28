/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:29:01 by aamajane          #+#    #+#             */
/*   Updated: 2022/08/28 16:44:21 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	check_cmd(t_data *data, char **av, char **env)
{
	get_paths(data, env);
	get_cmd_arg(data, av[data->i]);
	if (!*data->cmd_arg)
	{
		ft_putstr_fd(": Command not found\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (cmd_is_valid(data->cmd_arg[0]))
		data->cmd_path = data->cmd_arg[0];
	else
		get_cmd_path(data, data->cmd_arg[0]);
}

void	get_paths(t_data *data, char **env)
{
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	data->paths = ft_split(env[i] + 5, ':');
	if (!data->paths)
		exit(puterror("Split Error"));
}

void	get_cmd_arg(t_data *data, char *av)
{
	data->cmd_arg = ft_split(av, ' ');
	if (!data->cmd_arg)
		exit(puterror("Split Error"));
}

void	get_cmd_path(t_data *data, char *cmd)
{
	int		i;

	data->ret = -1;
	i = -1;
	while (data->paths[++i] && data->ret == -1)
	{
		data->cmd_path = ft_strjoin(data->paths[i], "/");
		data->temp = data->cmd_path;
		data->cmd_path = ft_strjoin(data->temp, cmd);
		free(data->temp);
		if (!data->cmd_path)
			exit(puterror("Join Error"));
		data->ret = access(data->cmd_path, X_OK);
		if (data->ret == -1)
			free(data->cmd_path);
	}
	if (data->ret == -1)
	{
		ft_putstr_fd(data->cmd_arg[0], STDERR_FILENO);
		ft_putstr_fd(": Command not found\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

int	cmd_is_valid(char *cmd)
{
	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == -1)
			exit(puterror(cmd));
		return (1);
	}
	return (0);
}
