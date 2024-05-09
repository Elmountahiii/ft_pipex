#include "mandatory/pipex.h"

void check_leaks()
{
   system("leaks test");
}
int main(int argc, char **argv, char **env)
{
    atexit(check_leaks);
   
    return 0;
}
