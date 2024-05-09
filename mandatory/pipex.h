#ifndef PIPEX_H
#define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/lib.h"
# include <sys/wait.h>

typedef struct s_pipex {

    int	pipe_counter;
	int commands_count;
	int	**pipes;
	int	input_file;
	int	output_file;
	int	*p_id;
	int	arg_counter;
} t_pipex;

char	*ft_get_path(char *command, char **env);
int		ft_check_file(char * path, int flag);
char    *ft_check_path(char **env);
void	ft_execute(char *command, char **env);
int     ft_replace_fd(int dest, int src);
void	ft_open_files(int argc, char **argv, int *input, int *output);
void    ft_pipex(int argc, char **argv, char**env);
int     ft_count_commands(int argc);
int     **ft_allocate_pipes(int argc);
t_pipex *ft_init_struct(int argc, char **argv);
void	ft_wait_children(int *p_id);

#endif