/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:30:30 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/04 15:12:15 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	**ft_split(char *str)
{
	char 	**split;
	int		index;
	int		i;
	
	split = malloc(sizeof(char *) * (ft_count_words(str) + 1));
	if (!split)
		return (NULL);
	i = 0;
	index = 0;
	while (str && str[i])
	{
		if (str[i] && (ft_is_quote(str[i]) || !ft_is_space(str[i])))
		{
			split[index] = ft_substr(str, i);
			if (!split[index])
				return (ft_free_split(split, index), NULL);
			index ++;
			if (str[i] && ft_is_quote(str[i]))
				i = ft_skip_quotes(str, i);
			else if (str[i] && !ft_is_space(str[i]))
				i = ft_skip_space(str, i);
		}
		else
			i++;
	}
	return (split[index] = NULL, split);
}
