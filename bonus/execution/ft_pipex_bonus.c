/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:41:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 20:39:37 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"


void close_all(t_pipex *pipex)
{
	int i;

	i = 0;
	while (i < pipex->commands_count - 1)
	{
		close(pipex->pipes[i][0]);
		close(pipex->pipes[i][1]);
		i++;
	}
}
void close_parent_unused_pipes(t_pipex *pipex)
{
	if (pipex->c == 0)
	{
		close(pipex->pipes[pipex->c][1]);
	}else{
		close(pipex->pipes[pipex->c - 1][1]);
	}
}
void	ft_pipex(int argc, char **argv, char**env)
{
	t_pipex	*pipex;
	int 	p_id;

	pipex = ft_init_struct(argc, argv, env);
	if (pipex->is_here_doc)
	{
		ft_here_doc(pipex);
		pipex->arg_counter++;
	}
	p_id = 0;
	while (pipex->c < pipex->commands_count) {
    p_id = fork();
    if (p_id == 0) {
		
		if (pipex->c == 0)
		{
            dup2(pipex->input_file, STDIN_FILENO);
            close(pipex->input_file);
        } else {
            dup2(pipex->pipes[pipex->c - 1][0], STDIN_FILENO);
            close(pipex->pipes[pipex->c - 1][1]); // Close the write end of the previous pipe
        }
        if (pipex->c == (pipex->commands_count - 1)) {
            dup2(pipex->output_file, STDOUT_FILENO);
            close(pipex->output_file);
        } else {
            dup2(pipex->pipes[pipex->c][1], STDOUT_FILENO);
            close(pipex->pipes[pipex->c][0]); // Close the read end of the current pipe
        }
		close_all(pipex);
        ft_execute(argv[pipex->arg_counter], env);
    } else {
        pipex->c++;
        pipex->arg_counter++;
    }
}
	
	ft_clean_struct(pipex);	
	while (wait(NULL) > 0);
	
}
