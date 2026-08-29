/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:12:21 by nilim             #+#    #+#             */
/*   Updated: 2026/08/29 11:29:00 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

void	lstnewbck(t_list **lst, void *content)
{
	t_list	*new;
	t_list	*curr;

	curr = *lst;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return ;
	new->content = content;
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (curr != NULL && curr->next != NULL)
			curr = curr->next;
		curr->next = new;
	}
}

char	*strjoin(const char *s1, const char *s2)
{
	char			*str;
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	i;

	i = 0;
	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

int	intstrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i++;
	}
	if (str[i] == (char)c)
		return (i);
	return (-1);
}

char	*substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (i < len && s[j])
		substr[i++] = s[j++];
	substr[i] = '\0';
	return (substr);
}

// int	check_char(char *str, char *trg)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (strchr(trg, str[i]))
// 			return (i);
// 		i++;
// 	}
// 	return (0);
// }
