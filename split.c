/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gstronge <gstronge@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:28:58 by gstronge          #+#    #+#             */
/*   Updated: 2024/05/14 11:38:07 by gstronge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free_array(char **strstr)
{
	int	i;

	i = 1;
	free(strstr[0]);
	while (strstr[i] != NULL)
	{
		free(strstr[i]);
		i++;
	}
	free(strstr[i]);
	free(strstr);
	return (NULL);
}

int	ft_strnum(char const *s, char c, int strnum)
{
	int	i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (0);
	if (c == '\0' && i > 0)
		return (1);
	strnum = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
			strnum++;
		if (s[i] == c && s[i + 1] == '\0')
			strnum--;
		i++;
	}
	return (strnum);
}

int	ft_copystr(char const *s, char c, char **strstr, int index)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	strstr[index] = (char *)malloc((i + 1) * sizeof(char));
	if (strstr[index] == NULL)
		return (i);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		strstr[index][i] = s[i];
		i++;
	}
	strstr[index][i] = '\0';
	return (i);
}

char	**ft_split_ps(char const *s, char c)
{
	int		strnum;
	char	**strstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	strnum = 0;
	strnum = ft_strnum(s, c, strnum);
	strstr = (char **)malloc((strnum + 2) * sizeof(char *));
	if (strstr == NULL)
		return (NULL);
	strstr[i] = NULL;
	i++;
	while (i <= strnum)
	{
		while (s[j] == c)
			j++;
		j = j + ft_copystr(s + j, c, strstr, i);
		if (strstr[i] == NULL)
			return (ft_free_array(strstr));
		i++;
	}
	strstr[i] = NULL;
	return (strstr);
}
