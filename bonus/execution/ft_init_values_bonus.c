/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:37:30 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/14 22:25:51 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_init_values(t_pipex *pipex)
{
	pipex->pipe_counter = 0;
	pipex->arg_counter = 2;
	pipex->commands_count = 0;
	pipex->commands_name = NULL;
	pipex->is_here_doc = 0;
	pipex->limiter = NULL;
	pipex->pipes = NULL;
	pipex->p_id = NULL;
	pipex->input_file = -1;
	pipex->output_file = -1;
	pipex->c = 0;
}
