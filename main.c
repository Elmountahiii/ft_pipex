/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:05:02 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/27 15:05:59 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/pipex.h"

int main(int argc, char **argv, char ** env)
{
    (void) env;
   // int     c_pid;
    int     if_fd;
    char    *path;

    if (argc < 2)
        return (0);
    if_fd = ft_check_file(argv[1], O_RDONLY);
    path = ft_get_path(argv[2], env);
	printf("input fd : %d\npath : %s\n", if_fd, path);
    return 0;
}
