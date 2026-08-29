/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:12:17 by nilim             #+#    #+#             */
/*   Updated: 2026/08/29 11:29:46 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef
#  define DELIM '\n'
# endif
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		breaker(t_list **index, void *content);
char	*extractor(t_list **lst);
char	*get_next_line(int fd);

// utils
void	lstnewbck(t_list **lst, void *content);
char	*strjoin(const char *s1, const char *s2);
int		intstrchr(const char *str, int c);
char	*substr(const char *s, unsigned int start, size_t len);
// int		check_char(char *str, char *trg);

#endif 