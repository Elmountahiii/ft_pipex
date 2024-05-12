/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:10:31 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/11 19:03:38 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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
