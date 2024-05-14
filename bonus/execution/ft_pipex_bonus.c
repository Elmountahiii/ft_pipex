/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmountahi <elmountahi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:41:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 00:43:46 by elmountahi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"


static void	ft_read_from(t_pipex *pipex)
{
	if (pipex->pipe_counter == 0)
	{
		dup2(pipex->input_file, STDIN_FILENO);
	}
	else
		dup2(pipex->pipes[pipex->pipe_counter - 1][0], STDIN_FILENO);
		close(pipex->input_file);
		close(pipex->pipes[pipex->pipe_counter][0]);
}

static void	ft_write_to(t_pipex *pipex)
{
		dup2(pipex->output_file, STDOUT_FILENO);
		printf("pipe counter: %d\n", pipex->pipe_counter);
		printf("pipe c: %d\n", pipex->c);
		fflush(stdout); // Force the output to be written to the file
		close(pipex->pipes[pipex->pipe_counter][1]);
		close(pipex->output_file);	
}

void	ft_pipex(int argc, char **argv, char**env)
{
	t_pipex	*pipex;

	pipex = ft_init_struct(argc, argv, env);
	while (pipex->c < pipex->commands_count)
	{
		
		pipex->p_id[pipex->pipe_counter] = fork();
		if (pipex->p_id[pipex->pipe_counter] == -1)
			ft_error_exit("Error", "unable to fork");
		if (pipex->p_id[pipex->pipe_counter] == 0)
		{
			ft_write_to(pipex);
			ft_read_from(pipex);
			ft_execute(argv[pipex->arg_counter], env);
		}
		else
		{
			pipex->pipe_counter++;
			pipex->arg_counter++;
			pipex->c++;
		}
	}
	ft_clean_struct(pipex);
	while (wait(NULL) > 0)
	{
	}
}
