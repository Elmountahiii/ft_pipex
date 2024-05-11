/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:17:42 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/11 19:32:49 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_execute(char *command, char **env)
{
	char	*path;
	char	**commands;

	commands = ft_split(command);
	path = ft_get_path(commands[0],env);
	if (path)
		execv(path,commands);
	free(path);
	ft_free_split(commands, ft_split_count(commands));
}
