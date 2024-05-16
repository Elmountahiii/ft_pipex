/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_struct_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:36:25 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/16 13:31:58 by yel-moun         ###   ########.fr       */
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
	unlink("/tmp/here_doc");
	if (pipex->is_here_doc)
		free(pipex->limiter);
	ft_free_split(pipex->commands_name, ft_split_count(pipex->commands_name));
	while (i < (pipex->commands_count - 1))
	{
		close(pipex->pipes[i][0]);
		close(pipex->pipes[i][1]);
		free(pipex->pipes[i]);
		i++;
	}
	free(pipex->pipes);
	free(pipex->p_id);
	free(pipex);
}
