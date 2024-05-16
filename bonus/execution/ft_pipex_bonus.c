/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:41:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 21:29:23 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	close_all_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->commands_count - 1)
	{
		close(pipex->pipes[i][0]);
		close(pipex->pipes[i][1]);
		i++;
	}
}

void	ft_read_from(t_pipex *pipex)
{
	if (pipex->c == 0)
	{
		dup2(pipex->input_file, STDIN_FILENO);
		close(pipex->input_file);
	}
	else
	{
		dup2(pipex->pipes[pipex->c - 1][0], STDIN_FILENO);
		close(pipex->pipes[pipex->c - 1][1]);
	}
}

void	ft_write_to(t_pipex *pipex)
{
	if (pipex->c == (pipex->commands_count - 1))
	{
		dup2(pipex->output_file, STDOUT_FILENO);
		close(pipex->output_file);
	}
	else
	{
		dup2(pipex->pipes[pipex->c][1], STDOUT_FILENO);
		close(pipex->pipes[pipex->c][0]);
	}
	close_all_pipes(pipex);
}

void	ft_go_next_command(t_pipex *pipex)
{
	pipex->c++;
	pipex->arg_counter++;
}



void	ft_pipex(int argc, char **argv, char**env)
{
	t_pipex	*pipex;

	pipex = ft_init_struct(argc, argv);
	if (pipex->is_here_doc)
		ft_here_doc(pipex);
	while (pipex->c < pipex->commands_count)
	{
		pipex->p_id[pipex->c] = fork();
		if (pipex->p_id[pipex->c] == -1)
			ft_error_exit("Error", "unable to fork");
		if (pipex->p_id[pipex->c] == 0)
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
