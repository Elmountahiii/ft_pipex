/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cont_words.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:40:32 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/27 11:45:56 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_count_words(char *str, char dil)
{
	int	words;
	int i;

	if (!str || !dil)
		return (-1);
	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != dil)
		{
			while (str[i] && str[i] != dil)
				i++;
			
			words ++;	
		}
		else
		{
			while (str[i] && str[i] == dil)
				i++;
		}
	}
	
	return (words);
}
