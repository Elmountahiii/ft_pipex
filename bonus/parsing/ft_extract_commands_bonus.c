/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_commands_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmountahi <elmountahi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:41:29 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 15:29:30 by elmountahi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_extract_commands(char **argv, t_pipex *pipex)
{
	char	**commands;
	int		i;
	int		c;

	c = 0;
	pipex->commands_name = malloc(sizeof(char *) * (pipex->commands_count + 1));
	if (!pipex->commands_name)
		return (ft_clean_struct(pipex) ,ft_error_exit("Error", "malloc"));
	if (pipex->is_here_doc)
		i =	1;
	else
		i = 0;
	// printf("i = %d\n", i);
	// printf("pipex->commands_count = %d\n", pipex->commands_count);
	// printf("argv[%d] = %s\n", i,argv[i + 2]);
	// exit(0);
	while (c < pipex->commands_count)
	{
		commands = ft_split(argv[i + 2]);
		if (!commands)
			return (ft_clean_struct(pipex) ,ft_error_exit("Error", "malloc"));
		pipex->commands_name[c] = ft_strdup(commands[0]);
		ft_free_split(commands, ft_split_count(commands));
		c ++;
		i ++;
	}
	pipex->commands_name[c] = NULL;
}
