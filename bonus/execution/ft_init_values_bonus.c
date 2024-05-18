/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:37:30 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 12:37:45 by yel-moun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_init_values(t_pipex *pipex)
{
	pipex->commands_number = 0;
	pipex->pipes = NULL;
	pipex->pipes_number = 0;
	pipex->input_file = -1;
	pipex->output_file = -1;
	pipex->p_id = -1;
	pipex->arg_counter = 2;
	pipex->is_here_doc = 0;
	pipex->limiter = NULL;
	pipex->counter = 0;
}
