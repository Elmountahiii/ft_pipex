/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:32:25 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/04 12:11:54 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_count_words(char *str)
{
	int	words;
	int i;

	i = 0;
	words = 0;
	while (str && str[i])
	{
		if (str[i] && ft_is_quote(str[i]))
		{
			i = ft_skip_quotes(str, i);
			words ++;
		}else if (str[i] && !ft_is_space(str[i]))
		{
			i = ft_skip_space(str, i);
			words ++;	
		}
		else
			i ++;
	}
	return (words);
}
