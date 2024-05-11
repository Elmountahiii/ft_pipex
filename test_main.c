#include "mandatory/pipex.h"

void check_leaks()
{
   system("leaks test");
}
int main(int argc, char **argv, char **env)
{
    (void) env;
    atexit(check_leaks);
    t_pipex *pipex = malloc(sizeof(t_pipex));
    int i = 0;

    pipex->commands_count = ft_count_commands(argc);
    ft_extract_commands(argv,pipex);
    while (pipex->commands_name && pipex->commands_name[i])
    {
       printf("%d : %s\n",i, pipex->commands_name[i]);
       i ++;
    }
    ft_free_split(pipex->commands_name, ft_split_count(pipex->commands_name));
    free(pipex);
   
    return 0;
}
