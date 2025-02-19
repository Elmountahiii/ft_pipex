/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_command_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:55:26 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/18 13:55:28 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_count_commands(int argc, t_pipex *pipex)
{
	int	start;

	if (pipex->is_here_doc)
		start = 3;
	else
		start = 2;
	while (start < argc -1)
	{
		start++;
		pipex->commands_number++;
	}
}
