/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:28:04 by aamajane          #+#    #+#             */
/*   Updated: 2022/08/28 16:43:51 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(t_data *data, char **av, char **env)
{
	if (data->in == -1 || data->out == -1)
		exit(EXIT_FAILURE);
	if (dup2(data->in, STDIN_FILENO) == -1)
		exit(puterror("Dup2 Error"));
	if (dup2(data->out, STDOUT_FILENO) == -1)
		exit(puterror("Dup2 Error"));
	close_all_fd(data);
	check_cmd(data, av, env);
	if (execve(data->cmd_path, data->cmd_arg, env) == -1)
		exit(puterror(data->cmd_arg[0]));
}

void	close_all_fd(t_data *data)
{
	close(data->infd);
	close(data->outfd);
	close(data->end_p1[0]);
	close(data->end_p1[1]);
	close(data->end_p2[0]);
	close(data->end_p2[1]);
}

int	puterror(char *str)
{
	perror(str);
	return (EXIT_FAILURE);
}
