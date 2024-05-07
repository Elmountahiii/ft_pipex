/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:05:01 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/06 19:12:39 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_count_commands(int argc)
{
	int	start;
    int i;
	
	start = 2;
    i = 0;
	while (start < argc -1)
    {
        start++;
		i ++;
    }
	return(i);
}
