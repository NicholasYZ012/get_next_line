/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:11:51 by nilim             #+#    #+#             */
/*   Updated: 2026/08/29 11:29:50 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int	breaker(t_list **index, void *content)
{
	char	*rem;

	if (content == NULL || intstrchr(content, DELIM) == -1)
		return (0);
	rem = substr(content, 0, BUFFER_SIZE + 1);
	while (intstrchr(rem, DELIM) != -1)
	{
		lstnewbck(index, substr(rem, 0, intstrchr(rem, DELIM) + 1));
		content = substr(rem, intstrchr(rem, DELIM) + 1, BUFFER_SIZE + 1);
		free(rem);
		rem = content;
	}
	if (*rem)
		lstnewbck(index, substr(rem, 0, BUFFER_SIZE + 1));
	free(rem);
	return (1);
}

char	*extractor(t_list **lst)
{
	char	*line;
	char	*temp;
	t_list	*next;

	if (*lst == NULL)
		return (NULL);
	line = substr((*lst)->content, 0, BUFFER_SIZE);
	while (intstrchr(line, DELIM) == -1 && (*lst)->next)
	{
		free((*lst)->content);
		next = (*lst)->next;
		free(*lst);
		*lst = next;
		temp = strjoin(line, (*lst)->content);
		free(line);
		line = temp;
	}
	free((*lst)->content);
	next = (*lst)->next;
	free(*lst);
	*lst = next;
	return (line);
}

char	*get_next_line(int fd)
{
	static t_list	*index[1024];
	char			buf[BUFFER_SIZE + 1];
	int				n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	n = 0;
	while (n < BUFFER_SIZE + 1)
		buf[n++] = 0;
	while (read(fd, buf, BUFFER_SIZE) > 0 && !breaker(&index[fd], buf))
	{
		n = 0;
		while (buf[n])
			n++;
		buf[n] = 0;
		n = 0;
		lstnewbck(&index[fd], substr(buf, 0, BUFFER_SIZE + 1));
		while (buf[n])
			buf[n++] = 0;
	}
	return (extractor(&index[fd]));
}

// #include <fcntl.h>
// #include <stdio.h>
// int main(int argc, char *argv[]){
// 	char	*sent;
// 	if (argc == 2)
// 	{
// 		// printf("%d\n", intstrchr("apple", 'p'));
// 		int fd = open(argv[1], O_RDONLY);
// 		int fd2 = open("test2", O_RDONLY);
// 		while ((sent = get_next_line(fd)))
// 		{
// 			printf("1.line: %s#\n", sent);
// 			free(sent);
// 			sent = get_next_line(fd2);
// 			printf("2.line: %s#\n", sent);
// 			free(sent);
// 		}
// 		close(fd);
// 		close(fd2);
// 	}
// }
