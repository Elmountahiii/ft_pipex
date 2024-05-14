/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:36:29 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/14 21:36:03 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_check_commands(char **env, t_pipex *pipex)
{
	int		i;
	char	*path;

	i = 0;
	while (i < pipex->commands_count)
	{
		path = ft_get_path(pipex->commands_name[i], env);
		if (!path)
		{
			ft_command_not_found(pipex->commands_name[i]);
			ft_clean_struct(pipex);
			exit(1);
		}
		free(path);
		i ++;
	}
}
