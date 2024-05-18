/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:13:37 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/18 13:56:59 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_init_values(t_pipex *pipex)
{
	pipex->commands_number = 0;
	pipex->pipes = NULL;
	pipex->pipes_number = 0;
	pipex->input_file = -1;
	pipex->output_file = -1;
	pipex->p_id = -1;
	pipex->arg_counter = 2;
	pipex->counter = 0;
}
