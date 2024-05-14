/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_pId_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:35:27 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/14 21:35:43 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_allocate_pid(t_pipex *pipex)
{
	pipex->p_id = malloc(sizeof(int) * (pipex->commands_count));
	if (!pipex->p_id)
	{
		ft_clean_struct(pipex);
		ft_error_exit("Error", "malloc");
	}
}
