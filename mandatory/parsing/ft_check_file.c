/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:07:48 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/07 11:10:19 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int ft_check_file(char * path, int flag)
{
	int	fd;

	fd = open(path, flag);
	if (fd == -1)
		ft_perror_exit("\033[0;31mError with input_fd.\033[0m\n");
	return (fd);
}