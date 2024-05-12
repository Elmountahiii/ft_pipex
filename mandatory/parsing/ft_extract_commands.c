/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:55:02 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/12 14:41:01 by yel-moun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_extract_commands(char **argv, t_pipex *pipex)
{
	char	**commands;
	int		i;

	i = 0;
	pipex->commands_name = malloc(sizeof(char *) * (pipex->commands_count + 1));
	if (!pipex->commands_name)
	{
		ft_clean_struct(pipex);
		ft_error_exit("Error", "malloc");
	}
	while (i < pipex->commands_count)
	{
		commands = ft_split(argv[i + 2]);
		if (!commands)
		{
			ft_clean_struct(pipex);
			ft_error_exit("Error", "malloc");
		}
		pipex->commands_name[i] = ft_strdup(commands[0]);
		ft_free_split(commands, ft_split_count(commands));
		i ++;
	}
	pipex->commands_name[i] = NULL;
}
