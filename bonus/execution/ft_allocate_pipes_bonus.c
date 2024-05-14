/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_pipes_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:35:42 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/14 21:26:45 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_allocate_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->pipes = malloc(sizeof(int *) * (pipex->commands_count + 1));
	if (!pipex->pipes)
	{
		ft_clean_struct(pipex);
		ft_error_exit("Error", "malloc");
	}
	while (i < pipex->commands_count)
	{
		pipex->pipes[i] = malloc(sizeof(int) * 2);
		if (!pipex->pipes[i] || pipe(pipex->pipes[i]) == -1)
		{
			ft_clean_struct(pipex);
			ft_error_exit("Error", "malloc");
		}
		i ++;
	}
	pipex->pipes[i] = NULL;
}
