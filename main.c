/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:05:02 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/29 16:00:09 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/pipex.h"

void check_leaks()
{
    system("leaks pipex");
}
int main(int argc, char **argv, char ** env)
{
    (void) env;
    int     if_fd;
    char    *path;
    char    **command_1;
    

    if (argc < 2)
        return (0);
    if_fd = ft_check_file(argv[1], O_RDONLY);
    path = ft_get_path(argv[2], env);
    command_1 =  ft_split(argv[2]);
	printf("input fd : %d\npath : %s\n", if_fd, path);
    printf("command is %s\n",command_1[0]);
    ft_free_split(command_1,ft_split_count(command_1));
    atexit(check_leaks);
    return 0;
}
