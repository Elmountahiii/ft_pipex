/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:32:25 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/29 15:06:54 by yel-moun         ###   ########.fr       */
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
		if (str[i] && !ft_is_space(str[i]))
		{
			while (str[i] && !ft_is_space(str[i]))
				i++;
			words ++;	
		}
		else
			i ++;
	}
	return (words);
}
