/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:57:21 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/18 13:58:42 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	close_all_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->commands_number - 1)
	{
		close(pipex->pipes[i][0]);
		close(pipex->pipes[i][1]);
		i++;
	}
	close(pipex->input_file);
	close(pipex->output_file);
}

void	ft_read_from(t_pipex *pipex)
{
	if (pipex->counter == 0)
		dup2(pipex->input_file, STDIN_FILENO);
	else
		dup2(pipex->pipes[pipex->counter - 1][0], STDIN_FILENO);
}

void	ft_write_to(t_pipex *pipex)
{
	if (pipex->counter == (pipex->commands_number - 1))
		dup2(pipex->output_file, STDOUT_FILENO);
	else
		dup2(pipex->pipes[pipex->counter][1], STDOUT_FILENO);
	close_all_pipes(pipex);
}

void	ft_go_next_command(t_pipex *pipex)
{
	pipex->counter++;
	pipex->arg_counter++;
}

void	ft_pipex(int argc, char **argv, char**env)
{
	t_pipex	*pipex;

	pipex = ft_init_struct(argc, argv);
	while (pipex->counter < pipex->commands_number)
	{
		pipex->p_id = fork();
		if (pipex->p_id == -1)
			ft_error_exit("Error", "unable to fork");
		if (pipex->p_id == 0)
		{
			ft_read_from(pipex);
			ft_write_to(pipex);
			ft_execute(argv[pipex->arg_counter], env, pipex);
		}
		else
			ft_go_next_command(pipex);
	}
	ft_clean_struct(pipex);
	while (wait(NULL) > 0)
	{
	}
}
