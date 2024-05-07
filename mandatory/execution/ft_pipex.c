/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:42:32 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/07 13:17:58 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void    ft_pipex(int argc, char **argv, char**env)
{
	t_pipex *pipex;
	
	pipex = ft_init_struct(argc, argv); 
	while (pipex->arg_counter < (argc - 1))
	{
		if ((pipex->p_id[pipex->pipe_counter] = fork()) == -1)
			ft_perror_exit("Error With Fork\n");
		if (pipex->p_id[pipex->pipe_counter] == 0)
		{
			if(pipex->arg_counter == 2)
				ft_replace_fd(pipex->input_file,STDIN_FILENO);
			else
				ft_replace_fd(pipex->pipes[pipex->pipe_counter][1], STDIN_FILENO);
			ft_execute(argv[pipex->arg_counter], env);
		}else
		{
				pipex->pipe_counter++;
				pipex->arg_counter++;
		}
	}
	ft_wait_children(pipex->p_id);
}
