/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:13:37 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/11 16:20:20 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_init_values(t_pipex *pipex)
{
	pipex->pipe_counter = 0;
	pipex->arg_counter = 2;
	pipex->commands_count = 0;
	pipex->commands_name = NULL;
	pipex->pipes = NULL;
	pipex->p_id = NULL;
	pipex->input_file = -1;
	pipex->output_file = -1;
}
