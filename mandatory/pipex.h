#ifndef PIPEX_H
#define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_get_command_path(char *command);
int		ft_check_file(char * path, int flag);
void	ft_perror_exit();

#endif