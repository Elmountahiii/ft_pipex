/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_children.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:04:04 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/07 16:30:28 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_wait_children(int *p_id)
{
	int i;

	i = 0;
	while (p_id && p_id[i])
		i ++;
	printf("\033[0;34mWaiting all %d children ...\033[0m\n",i);
	i = 0;
	while (p_id && p_id[i])
	{
		waitpid(p_id[i],NULL, 0);
		i ++;
	}
	printf("\033[0;32mSuccessfully executing all commands\033[0m\n");
}