/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:52:02 by aamajane          #+#    #+#             */
/*   Updated: 2022/08/28 16:45:46 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac != 5)
	{
		ft_putstr_fd("Invalid number of arguments\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	creat_pipe(data.end_p1);
	creat_pipe(data.end_p2);
	open_files(&data, ac, av);
	data.i = 1;
	while (++data.i < ac - 1)
		pipex(&data, ac, av, env);
	close_all_fd(&data);
	while (wait(NULL) != -1)
		;
	return (0);
}
