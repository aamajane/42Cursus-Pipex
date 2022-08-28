/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:20:05 by aamajane          #+#    #+#             */
/*   Updated: 2022/08/28 16:51:57 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	here_doc(t_data *data, int ac, char **av)
{
	data->infd = data->end_p1[0];
	data->outfd = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (data->outfd == -1)
		perror(av[ac - 1]);
	data->limiter = ft_strjoin(av[2], "\n");
	if (!data->limiter)
		exit(puterror("Join Error"));
	data->file = ft_strdup("");
	put_pipe_heredoc(ac);
	data->line = get_next_line(STDIN_FILENO);
	while (ft_strncmp(data->line, data->limiter, ft_strlen(data->line) + 1))
	{
		data->temp = data->file;
		data->file = ft_strjoin(data->temp, data->line);
		free(data->temp);
		free(data->line);
		put_pipe_heredoc(ac);
		data->line = get_next_line(STDIN_FILENO);
	}
	ft_putstr_fd(data->file, data->end_p1[1]);
	free(data->line);
	free(data->file);
	free(data->limiter);
}

void	put_pipe_heredoc(int ac)
{
	int	j;

	j = -1;
	while (++j < ac - 5)
		ft_putstr_fd("pipe ", STDIN_FILENO);
	ft_putstr_fd("heredoc> ", STDIN_FILENO);
}
