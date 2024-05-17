/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:05:01 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/11 15:46:28 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_count_commands(int argc, t_pipex *pipex)
{
	int	start;

	start = 2;
	while (start < argc -1)
	{
		start++;
		pipex->commands_number++;
	}
}
