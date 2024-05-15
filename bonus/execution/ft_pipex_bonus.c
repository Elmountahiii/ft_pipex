/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmountahi <elmountahi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:41:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 14:30:21 by elmountahi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"


// static void	ft_read_from(t_pipex *pipex)
// {
// 	if (pipex->c == 0)
// 	{
// 		dup2(pipex->input_file, STDIN_FILENO);
// 	}
// 	else
// 		dup2(pipex->pipes[pipex->pipe_counter - 1][0], STDIN_FILENO);
// 		close(pipex->input_file);
// }

// static void	ft_write_to(t_pipex *pipex)
// {
// 		if (pipex->c != pipex->commands_count -1)
// {
	
	 
// 			dup2(pipex->pipes[pipex->pipe_counter][1], STDOUT_FILENO);
	
// }
// 		else
// 		{
// 			dup2(pipex->output_file, STDOUT_FILENO);		
// 			close(pipex->output_file);	
// 		}
// }
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
	printf("pipex->pipes_number = %d\n", pipex->pipes_number);
	fflush(stdout);
	p_id = 0;
	
	while (pipex->c < pipex->commands_count) {
    p_id = fork();
    if (p_id == 0) {
        if (pipex->c == 0) {
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

        ft_execute(argv[pipex->arg_counter], env);
    } else {
        close_parent_unused_pipes(pipex); // Close unused pipes in the parent process
        printf("pipex->c = %d\n", pipex->c);
        fflush(stdout);
        pipex->c++;
        pipex->arg_counter++;
    }
}
	
	ft_clean_struct(pipex);
	while (wait(NULL) > 0);
	
}
