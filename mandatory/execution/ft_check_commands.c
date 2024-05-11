/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:10:31 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/11 11:26:52 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void ft_check_commands(int argc, char **argv, char **env, t_pipex *pipex)
{
	int commands_counter;
	char **command_list;
	char *command;

	commands_counter = 2;
	while (commands_counter < (argc -1) )
	{
		command_list = ft_split(argv[commands_counter]);
		if (!command_list)
		{
			free(pipex);
			ft_error_exit("",NULL);
		}
		command = ft_get_path(command_list[0], env);
		if (!command)
		{
			free(pipex);
			ft_free_split(command_list, ft_split_count(command_list));
			ft_error_exit("Command not found", argv[commands_counter]);
			exit(1);
		}
		free(command);
		ft_free_split(command_list, ft_split_count(command_list));
		commands_counter ++;
	}
}
