/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:41:34 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/18 13:55:07 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*ft_check_path(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4))
			return (ft_strchr(env[i], '/'));
		i ++;
	}
	return (NULL);
}
