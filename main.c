/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:05:02 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/02 18:57:37 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/pipex.h"

void check_leaks()
{
   system("leaks pipex");
}
int main(int argc, char **argv, char **env)
{
    // (void ) env;
	// (void ) argv;
	// (void) argc;

    
    int     if_fd;
   pid_t	cp_id;
	int		pipe_fd[2];
	
	if (argc < 2)
        return (0);
	if (pipe(pipe_fd) == -1)
		 ft_perror_exit("Error \n");
	
    if_fd = ft_check_file(argv[1], O_RDONLY);
	cp_id = fork();
	if (cp_id == 0)
	{
		dup2(if_fd, 0);
		close(pipe_fd[0]);
		dup2(pipe_fd[1], 1);
		ft_execute(argv[2],env);
	}else
	{
		waitpid(cp_id, NULL, 0);
		printf("done\n");
	}
	
    
       return 0;
}
