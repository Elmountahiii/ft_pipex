#include "./mandatory/pipex.h"

int main(int argc, char  *argv[])
{
	(void) argc;
	printf("%s\n",argv[1]);
	int is_here_doc = ft_strncmp(argv[1],"here_doc", ft_strlen("here_doc"));
	if (!is_here_doc)
		printf("yes\n");
	else
		printf("no \n");
	return 0;
}
