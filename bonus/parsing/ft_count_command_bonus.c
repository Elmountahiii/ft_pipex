/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_command_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:41:32 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/14 21:39:22 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_count_commands(int argc, t_pipex *pipex)
{
	int	start;
	int	i;

	start = 2;
	i = 0;
	while (start < argc -1)
	{
		start++;
		i ++;
	}
	pipex->commands_count = i;
}
