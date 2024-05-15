/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:41:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/14 21:39:44 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*ft_get_path(char *command, char **env)
{
	char	**path_list;
	int		i;
	char	*path;

	if (!ft_check_path(env))
	{
		ft_command_not_found(command);
		exit(1);
	}
	i = 0;
	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, F_OK) != -1 && access(command, X_OK) != -1)
			return (ft_strdup(command));
		ft_command_not_found(command);
		exit(1);
	}
	path_list = ft_split_dil(ft_check_path(env), ':');
	while (command && path_list && path_list[i])
	{
		path = ft_join_three(path_list[i], "/", command);
		if (access(path, F_OK) != -1 && access(path, X_OK) != -1)
		{
			ft_free_split(path_list, ft_split_count(path_list));
			return (path);
		}
		free(path);
		i ++;
	}
	ft_free_split(path_list, ft_split_count(path_list));
	return (NULL);
}
