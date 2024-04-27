/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:04:58 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/27 15:18:37 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_get_path(char *command, char **env)
{
	char	*path;
	(void) command;

	path = ft_check_path(env);
	if (!path)
		ft_perror_exit("Error : PATH NOT FOUND.\n");
	return (path);
}
