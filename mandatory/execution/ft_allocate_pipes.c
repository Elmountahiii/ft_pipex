/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:08 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/08 20:55:53 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	**ft_allocate_pipes(int argc)
{
	int	**pipes;
	int	commands_count;
	int	i;
	//printf("\033[0;34mTrying to count commands.....\033[0m\n");
	commands_count = ft_count_commands(argc);
	//printf("\033[0;32m%d commands\033[0m\n",commands_count);
	i = 0;
	//printf("\033[0;34mTrying to allocate pipes.....\033[0m\n");
	pipes = malloc(sizeof(int *) * (commands_count + 1));
	if (!pipes)
		ft_perror_exit("\033[0;31mError allocating pipes.\033[0m\n");
	//printf("\033[0;32mSuccessfully allocating pipes\033[0m\n");
	// free
	//printf("\033[0;34mTrying to pipe.....\033[0m\n");
	while (i < commands_count)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (pipe(pipes[i]) == -1)
			ft_perror_exit("\033[0;31mError pipe:.\033[0m\n");
		i ++; 
	}
	pipes[i] = NULL;
	//printf("\033[0;32mSuccessfully allocating %d pipes\033[0m\n",i);
	return (pipes);
}
