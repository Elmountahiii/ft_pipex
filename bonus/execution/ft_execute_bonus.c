/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:36:22 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 21:30:17 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_execute(char *command, char **env, t_pipex *pipex)
{
	char	*path;
	char	**commands;
	int		i;

	commands = ft_split(command);
	if (ft_strlen(commands[0]) != 0
		&& (commands[0][0] == '/' || commands[0][0] == '.'))
		path = commands[0];
	else
		path = ft_get_path(commands[0], env);
	if (!path)
	{
		ft_command_not_found(commands[0]);
		ft_clean_struct(pipex);
		exit(1);
	}
	i = execv(path, commands);
	if (i == -1)
	{
		perror("Error");
		ft_clean_struct(pipex);
		exit(1);
	}
}
