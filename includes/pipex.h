/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:50:36 by aamajane          #+#    #+#             */
/*   Updated: 2022/08/28 16:51:45 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

# define BUFFER_SIZE	10

typedef struct s_data
{
	int		i;
	int		in;
	int		out;
	int		ret;
	int		infd;
	int		outfd;
	int		end_p1[2];
	int		end_p2[2];
	pid_t	pid;
	char	*limiter;
	char	*line;
	char	*file;
	char	*temp;
	char	**paths;
	char	**cmd_arg;
	char	*cmd_path;
}				t_data;

// pipex.c
void	open_files(t_data *data, int ac, char **av);
void	creat_pipe(int end[2]);
void	pipex(t_data *data, int ac, char **av, char **env);
void	chose_in(t_data *data);
void	chose_out(t_data *data, int ac);

// child_process.c
void	child_process(t_data *data, char **av, char **env);
void	close_all_fd(t_data *data);
int		puterror(char *str);

// check_cmd.c
void	check_cmd(t_data *data, char **av, char **env);
void	get_paths(t_data *data, char **env);
void	get_cmd_arg(t_data *data, char *av);
void	get_cmd_path(t_data *data, char *cmd);
int		cmd_is_valid(char *cmd);

// heredoc_bonus.c
void	here_doc(t_data *data, int ac, char **av);
void	put_pipe_heredoc(int ac);

// get_next_line.c
char	*get_next_line(int fd);
void	get_file(int fd, char **stock, char **line, char **buf);
char	*get_line(char **stock, char **line);
void	get_free(char **str);

// utils_1.c
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);

// utils_2.c
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// utils_3.c
char	**ft_split(char const *s, char c);

#endif
