/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:42:10 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/07 13:11:29 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_pipex *ft_init_struct(int argc, char **argv)
{
	t_pipex *pipex;
	    printf("\033[0;32mProgram started.\033[0m\n"); 
		
	 printf("\033[0;34mTrying to allocate the struct .....\033[0m\n");
	pipex = malloc(sizeof(t_pipex));
	
	if(!pipex)
		ft_perror_exit("\033[0;31mError Allocating Pipex Struct.\033[0m\n");
	printf("\033[0;32mSuccessfully allocating the pipex struct. \033[0m\n");
	ft_open_files(argc, argv, &pipex->input_file, &pipex->output_file);
	pipex->pipes = ft_allocate_pipes(argc);
	pipex->pipe_counter = 0;
	pipex->p_id = malloc(sizeof(int) * ft_count_commands(argc));
	pipex->arg_counter = 2;
	printf("\033[0;32mSuccessfully init the pipex struct. \033[0m\n");
	return (pipex);
}
