/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmountahi <elmountahi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:43:51 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 12:37:22 by elmountahi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/lib.h"
# include <sys/wait.h>

typedef struct s_pipex
{
	int		pipe_counter;
	int		command_executed;
	int		commands_count;
	char	**commands_name;
	int		**pipes;
	int		input_file;
	int		output_file;
	int		*p_id;
	int		arg_counter;
	int		is_here_doc;
	char	*limiter;
	int		pipes_number;
	int		c;
}	t_pipex;

char	*ft_get_path(char *command, char **env);
int		ft_check_file(char *path, int flag);
char	*ft_check_path(char **env);
void	ft_execute(char *command, char **env, t_pipex *pipex);
int		ft_replace_fd(int dest, int src);
void	ft_open_files(int argc, char **argv, t_pipex *pipex);
void	ft_pipex(int argc, char **argv, char**env);
void	ft_count_commands(int argc, t_pipex *pipex);
void	ft_allocate_pipes(t_pipex *pipex);
void	ft_allocate_pid(t_pipex *pipex);
t_pipex	*ft_init_struct(int argc, char **argv, char **env);
void	ft_check_commands(char **env, t_pipex *pipex);
void	ft_validate_commands(char **env, t_pipex *pipex);
void	ft_extract_commands(char **argv, t_pipex *pipex);
void	ft_init_values(t_pipex *pipex);
void	ft_clean_struct(t_pipex *pipex);
void	ft_init_heredoc(char **argv, t_pipex *pipex);
void	ft_check_here_doc(char *str, t_pipex *pipex);
void	ft_debug(t_pipex *pipex);
void	ft_here_doc(t_pipex *pipex);

#endif