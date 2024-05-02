#ifndef PIPEX_H
#define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../lib/lib.h"
# include <sys/wait.h>

char	*ft_get_path(char *command, char **env);
int		ft_check_file(char * path, int flag);
void    ft_perror_exit(char *error);
char    *ft_check_path(char **env);
void	ft_execute(char *command, char **env);

#endif