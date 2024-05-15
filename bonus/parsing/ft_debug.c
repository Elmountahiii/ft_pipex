/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:53:53 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 21:35:17 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_debug(t_pipex *pipex)
{
	int	i;

	i = 0;
	printf("is here_doc : %d\n", pipex->is_here_doc);
	printf("LIMITER : %s\n", pipex->limiter);
	printf("input_fd : %d\n", pipex->input_file);
	printf("output_fd : %d\n", pipex->output_file);
	printf("commands count : %d\n", pipex->commands_count);
	printf("pipe counter : %d\n", pipex->pipe_counter);
	printf("arg counter : %d\n", pipex->arg_counter);
	printf("pipes number : %d\n", pipex->pipes_number);
	printf("commands name : \n");
	while (pipex->commands_name && pipex->commands_name[i])
	{
		printf("%d : %s\n", i, pipex->commands_name[i]);
		i++;
	}
}
