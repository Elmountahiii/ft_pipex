/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:39:59 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/14 21:39:06 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	ft_check_file(char *path, int flag)
{
	int	fd;

	fd = open(path, flag);
	if (fd == -1)
		ft_error_exit("no such file or directory", path);
	return (fd);
}
