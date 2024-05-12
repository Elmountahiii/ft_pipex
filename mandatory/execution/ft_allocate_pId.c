/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_pId.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:55:34 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/11 18:59:46 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_allocate_pid(t_pipex *pipex)
{
	pipex->p_id = malloc(sizeof(int) * (pipex->commands_count));
	if (!pipex->p_id)
	{
		ft_clean_struct(pipex);
		ft_error_exit("Error", "malloc");
	}
}
