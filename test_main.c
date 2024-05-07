#include "mandatory/pipex.h"
int main(int argc, char const *argv[])
{
    int i = 0;
    (void) argc;
    // (void) argv;
    char **commands = ft_split((char *)argv[1]);
    while (commands && commands[i])
    {
        printf("%d : %s\n",i,commands[i]);
        i++;
    }
    // char *str = "'{printf \"%-15s %5d\n\", $1, $3}'";
    // int i = 0;
    // printf("%d characters in str\n",ft_count_allocation(str,&i));
    // printf("i = %d",i);
    
    return 0;
}
