/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:26:12 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/11 19:04:44 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_validate_commands(char **env, t_pipex *pipex)
{
	char	*path;
	int		i;

	i = 0;
	path = ft_check_path(env);
	if (!path)
	{
		while (pipex->commands_name && pipex->commands_name[i])
		{
			ft_command_not_found(pipex->commands_name[i]);
			i ++;
		}
		ft_clean_struct(pipex);
		exit(1);
	}
	else
		ft_check_commands(env, pipex);
}
