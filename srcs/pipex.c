/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:22:26 by aamajane          #+#    #+#             */
/*   Updated: 2022/08/28 16:44:12 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	open_files(t_data *data, int ac, char **av)
{
	data->infd = open(av[1], O_RDONLY);
	if (data->infd == -1)
		perror(av[1]);
	data->outfd = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->outfd == -1)
		perror(av[ac - 1]);
}

void	creat_pipe(int end[2])
{
	if (pipe(end) == -1)
		exit(puterror("Pipe Error"));
}

void	pipex(t_data *data, int ac, char **av, char **env)
{
	chose_in(data);
	chose_out(data, ac);
	data->pid = fork();
	if (data->pid == -1)
		exit(puterror("Fork Error"));
	if (data->pid == 0)
		child_process(data, av, env);
}

void	chose_in(t_data *data)
{
	if (data->i == 2)
		data->in = data->infd;
	else
	{
		if (!(data->i % 2))
			data->in = data->end_p2[0];
		else
			data->in = data->end_p1[0];
	}
}

void	chose_out(t_data *data, int ac)
{
	if (data->i == ac - 2)
		data->out = data->outfd;
	else
	{
		if (!(data->i % 2))
		{
			close(data->end_p1[0]);
			close(data->end_p1[1]);
			creat_pipe(data->end_p1);
			data->out = data->end_p1[1];
		}
		else
		{
			close(data->end_p2[0]);
			close(data->end_p2[1]);
			creat_pipe(data->end_p2);
			data->out = data->end_p2[1];
		}
	}
}
