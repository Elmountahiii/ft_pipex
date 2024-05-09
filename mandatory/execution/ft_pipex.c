/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:42:32 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/09 17:56:57 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void    ft_pipex(int argc, char **argv, char**env)
{
    t_pipex *pipex;

    pipex = ft_init_struct(argc, argv, env);
    while (pipex->arg_counter < (argc - 1))
    {
        if ((pipex->p_id[pipex->pipe_counter] = fork()) == -1)
            ft_error_exit("Error","unable to fork");
        if (pipex->p_id[pipex->pipe_counter] == 0)
        {
            if(pipex->pipe_counter == 0)
                dup2(pipex->input_file,STDIN_FILENO);
            else
                dup2(pipex->pipes[pipex->pipe_counter -1 ][0], STDIN_FILENO);
                
            close(pipex->pipes[pipex->pipe_counter][0]);
            
            if (pipex->arg_counter == (argc - 2))
                dup2(pipex->output_file, STDOUT_FILENO);
            else
                dup2(pipex->pipes[pipex->pipe_counter][1], STDOUT_FILENO);
             close(pipex->pipes[pipex->pipe_counter][1]);
            ft_execute(argv[pipex->arg_counter], env);
        }
        else
        {
             close(pipex->pipes[pipex->pipe_counter][1]);
            pipex->pipe_counter++;
            pipex->arg_counter++;
        }
    }
    int i = 0;
    while (i < pipex->pipe_counter)
    {
        close(pipex->pipes[i][0]);
        free(pipex->pipes[i]);
        i++;
    }
    free(pipex->pipes);

    while(wait(NULL) > 0);
    close(pipex->input_file);
    close(pipex->output_file);
}
