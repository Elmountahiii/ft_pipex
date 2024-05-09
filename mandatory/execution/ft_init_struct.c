/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:42:10 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/09 17:59:30 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_pipex *ft_init_struct(int argc, char **argv, char **env)
{
	t_pipex *pipex;
	pipex = malloc(sizeof(t_pipex));
	
	if(!pipex)
		ft_error_exit("Error","malloc");
	ft_open_files(argc, argv, &pipex->input_file, &pipex->output_file);
	ft_check_commands(argc, argv, env);
	pipex->pipes = ft_allocate_pipes(argc);
	pipex->pipe_counter = 0;
	pipex->p_id = malloc(sizeof(int) * ft_count_commands(argc));
	if (!pipex->p_id)
		ft_error_exit("Error","malloc");
	pipex->arg_counter = 2;
	return (pipex);
}
