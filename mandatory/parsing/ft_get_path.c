/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:04:58 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/11 14:51:25 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_get_path(char *command, char **env)
{	char	**path_list;
	int		i;
	char	*path;

	if (!ft_check_path(env))
	{
		ft_command_not_found(command);
		exit(1);
	}
	i = 0;
	path_list = ft_split_dil(ft_check_path(env),':');
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
