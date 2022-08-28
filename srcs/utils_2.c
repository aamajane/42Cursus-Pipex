/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamajane <aamajane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:04:22 by aamajane          #+#    #+#             */
/*   Updated: 2022/05/07 17:21:09 by aamajane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			write(fd, s++, 1);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		dst = (char *)malloc(sizeof(*dst));
	else if (i - start < len)
		dst = (char *)malloc(sizeof(*dst) * (i - start + 1));
	else
		dst = (char *)malloc(sizeof(*dst) * (len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[start] && i < len && start < ft_strlen(s))
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
