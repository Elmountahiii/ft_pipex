/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:42:32 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/08 20:54:08 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void    ft_pipex(int argc, char **argv, char**env)
{
    t_pipex *pipex;

    pipex = ft_init_struct(argc, argv);
    //printf("\033[0;34mTrying to execute commands ...\033[0m\n");
    while (pipex->arg_counter < (argc - 1))
    {
        if ((pipex->p_id[pipex->pipe_counter] = fork()) == -1)
            ft_perror_exit("Error With Fork\n");
        if (pipex->p_id[pipex->pipe_counter] == 0)
        {
           // printf("\033[0;34mStart of command %d ...\033[0m\n",pipex->pipe_counter);
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
            //printf("\033[0;31mError executing the command %d.\033[0m\n",pipex->pipe_counter);
            exit(1);
        }
        else
        {
          // close(pipex->pipes[pipex->pipe_counter][0]);
             close(pipex->pipes[pipex->pipe_counter][1]);
            pipex->pipe_counter++;
            pipex->arg_counter++;
        }
    }
    int i = 0;
    while (i < pipex->pipe_counter)
    {
        close(pipex->pipes[i][0]);
        i++;
    }
    while(wait(NULL) > 0);
    
}
