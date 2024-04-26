/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:05:02 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/26 22:32:50 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/pipex.h"

int main(int argc, char **argv, char ** env)
{
    (void) env;
    int     c_pid;
    int     if_fd;
    char    *command_path;

    if (argc < 3)
        return (0);
    if_fd = ft_check_file(argv[1], O_RDONLY);
    
    return 0;
}
