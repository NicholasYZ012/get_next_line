/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:11:51 by nilim             #+#    #+#             */
/*   Updated: 2026/08/25 19:58:17 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*store;
	char		buf[BUFFER_SIZE + 1];
	int			n;

	store = NULL;
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[BUFFER_SIZE + 1] = '\0';
		if (store == NULL)
			store = ft_strdup(buf);
		else
			store = ft_strjoin(store, buf);
		if (ft_strchr(buf, '\n'))
			break;
	}
	
}
