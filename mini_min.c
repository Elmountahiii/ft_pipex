#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
 #include <sys/wait.h>
    
int main(int argc, char const *argv[])
{
    int pipe_fd[2];
    char buffer[200];
    char *msg = "this message will be send through a pipe";
    int inf_fd = open("infile.txt",O_WRONLY);

    if (pipe(pipe_fd) == -1 || inf_fd == -1)
        return (1);
    pid_t cp_id = fork();
    pid_t cp_id2 = fork ();
    if (cp_id == 0)
    {
        // printf("this is child 1\n");
        // printf("cp_id2 : %d\n",cp_id2);
    }
    if (cp_id2 == 0 && cp_id == 0)
    {
          printf("2 : cp_id : %d\n",cp_id);
    }
    else {
        wait(NULL);
        printf("this is parent\n");
        printf("cp_id2 : %d\n",cp_id2);
    }

    
    return 0;
}