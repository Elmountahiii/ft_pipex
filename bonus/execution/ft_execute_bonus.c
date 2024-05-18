/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:36:22 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/18 13:54:29 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_execute(char *command, char **env, t_pipex *pipex)
{
	char	*path;
	char	**commands;

	commands = ft_split(command);
	if (!commands || !commands[0])
	{
		ft_command_not_found("");
		ft_clean_struct(pipex);
		exit(1);
	}
	if (ft_strncmp(commands[0], "./", 2) == 0
		|| ft_strncmp(commands[0], "/", 1) == 0)
		path = ft_strdup(commands[0]);
	else
		path = ft_get_path(commands[0], env);
	if (!path)
	{
		ft_command_not_found(commands[0]);
		ft_clean_struct(pipex);
		exit(1);
	}
	execv(path, commands);
	perror("Error");
	ft_clean_struct(pipex);
	exit(1);
}
