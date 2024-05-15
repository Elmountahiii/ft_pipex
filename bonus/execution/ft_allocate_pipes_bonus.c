/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_pipes_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:35:42 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 21:29:57 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_allocate_pipes(t_pipex *pipex)
{
	int	i;
	int	allocate;

	i = 0;
	allocate = pipex->commands_count - 1;
	pipex->pipes = malloc(sizeof(int *) * (allocate));
	if (!pipex->pipes)
	{
		ft_clean_struct(pipex);
		ft_error_exit("Error", "malloc");
	}
	while (i < allocate)
	{
		pipex->pipes[i] = malloc(sizeof(int) * 2);
		if (!pipex->pipes[i] || pipe(pipex->pipes[i]) == -1)
		{
			ft_clean_struct(pipex);
			ft_error_exit("Error", "malloc");
		}
		i ++;
		pipex->pipes_number++;
	}
}
