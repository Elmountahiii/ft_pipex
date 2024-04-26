/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:07:48 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/26 22:16:35 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int ft_check_file(char * path, int flag)
{
	int	fd;

	fd = open(path, flag);
	if (fd == -1)
		ft_perror_exit();

	return (fd);
}