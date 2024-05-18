/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:52:45 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/18 13:58:21 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/lib.h"
# include <sys/wait.h>

typedef struct s_pipex
{
	int		commands_number;
	int		**pipes;
	int		pipes_number;
	int		input_file;
	int		output_file;
	int		p_id;
	int		arg_counter;
	int		counter;
}	t_pipex;

char	*ft_get_path(char *command, char **env);
char	*ft_check_path(char **env);
void	ft_execute(char *command, char **env, t_pipex *pipex);
void	ft_open_files(int argc, char **argv, t_pipex *pipex);
void	ft_pipex(int argc, char **argv, char**env);
void	ft_count_commands(int argc, t_pipex *pipex);
void	ft_allocate_pipes(t_pipex *pipex);
t_pipex	*ft_init_struct(int argc, char **argv);
void	ft_init_values(t_pipex *pipex);
void	ft_clean_struct(t_pipex *pipex);

#endif