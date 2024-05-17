/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:38:53 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/11 18:39:49 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_clean_struct(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->input_file != -1)
		close(pipex->input_file);
	if (pipex->output_file != -1)
		close(pipex->output_file);
	ft_free_split(pipex->commands_name, ft_split_count(pipex->commands_name));
	while (i < (pipex->commands_number - 1))
	{
		close(pipex->pipes[i][0]);
		close(pipex->pipes[i][1]);
		free(pipex->pipes[i]);
		i++;
	}
	free(pipex->pipes);
	free(pipex);
}
