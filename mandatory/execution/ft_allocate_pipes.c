/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:16:08 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/09 17:58:45 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	**ft_allocate_pipes(int argc)
{
	int	**pipes;
	int	commands_count;
	int	i;
	commands_count = ft_count_commands(argc);
	i = 0;
	pipes = malloc(sizeof(int *) * (commands_count + 1));
	if (!pipes)
		ft_error_exit("Error","malloc");
	while (i < commands_count)
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (pipe(pipes[i]) == -1)
			ft_error_exit("Error","unable to fork");
		i ++; 
	}
	pipes[i] = NULL;
	return (pipes);
}
