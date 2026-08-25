/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nilim <nilim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 12:12:21 by nilim             #+#    #+#             */
/*   Updated: 2026/08/25 19:56:19 by nilim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*dup;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (s[i])
		dup[i] = s[i++];
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
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

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

int	check_char(char *str, char *trg)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(trg, str[i]))
			return (i);
		i++;
	}
	return (0);
}
