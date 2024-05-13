/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_struct_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:36:25 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/13 18:28:47 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_clean_struct(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->input_file != -1)
		close(pipex->input_file);
	if (pipex->output_file != -1)
		close(pipex->output_file);
	ft_free_split(pipex->commands_name, ft_split_count(pipex->commands_name));
	while (i < pipex->pipe_counter)
	{
		close(pipex->pipes[i][0]);
		free(pipex->pipes[i]);
		i++;
	}
	free(pipex->pipes);
	free(pipex->p_id);
	free(pipex);
}
