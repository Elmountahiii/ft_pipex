/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:41:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/13 18:31:35 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

static void	ft_read_from(t_pipex *pipex)
{
	if (pipex->pipe_counter == 0)
		dup2(pipex->input_file, STDIN_FILENO);
	else
		dup2(pipex->pipes[pipex->pipe_counter -1][0], STDIN_FILENO);
	close(pipex->pipes[pipex->pipe_counter][0]);
}

static void	ft_write_to(t_pipex *pipex, int argc)
{
	if (pipex->arg_counter == (argc - 2))
		dup2(pipex->output_file, STDOUT_FILENO);
	else
		dup2(pipex->pipes[pipex->pipe_counter][1], STDOUT_FILENO);
	close(pipex->pipes[pipex->pipe_counter][1]);
}

void	ft_pipex(int argc, char **argv, char**env)
{
	t_pipex	*pipex;

	pipex = ft_init_struct(argc, argv, env);
	while (pipex->arg_counter < (argc - 1))
	{
		pipex->p_id[pipex->pipe_counter] = fork();
		if (pipex->p_id[pipex->pipe_counter] == -1)
			ft_error_exit("Error", "unable to fork");
		if (pipex->p_id[pipex->pipe_counter] == 0)
		{
			ft_read_from(pipex);
			ft_write_to(pipex, argc);
			ft_execute(argv[pipex->arg_counter], env);
		}
		else
		{
			close(pipex->pipes[pipex->pipe_counter][1]);
			pipex->pipe_counter++;
			pipex->arg_counter++;
		}
	}
	ft_clean_struct(pipex);
	while (wait(NULL) > 0)
	{
	}
}
