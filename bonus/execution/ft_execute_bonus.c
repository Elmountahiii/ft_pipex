/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:36:22 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/14 21:36:26 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_execute(char *command, char **env)
{
	char	*path;
	char	**commands;

	commands = ft_split(command);
	path = ft_get_path(commands[0], env);
	if (path)
		execv(path, commands);
	free(path);
	ft_free_split(commands, ft_split_count(commands));
}
