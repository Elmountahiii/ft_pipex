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
	int		c;

	c = 0;
	pipex->commands_name = malloc(sizeof(char *)
			* (pipex->commands_number + 1));
	if (!pipex->commands_name)
		return (ft_clean_struct(pipex), ft_error_exit("Error", "malloc"));
	i = 0;
	while (c < pipex->commands_number)
	{
		commands = ft_split(argv[i + 2]);
		if (!commands)
			return (ft_clean_struct(pipex), ft_error_exit("Error", "malloc"));
		pipex->commands_name[c] = ft_strdup(commands[0]);
		ft_free_split(commands, ft_split_count(commands));
		c ++;
		i ++;
	}
	pipex->commands_name[c] = NULL;
}
