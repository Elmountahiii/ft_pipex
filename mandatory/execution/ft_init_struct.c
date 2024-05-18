/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:56:51 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/18 13:56:53 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_pipex	*ft_init_struct(int argc, char **argv)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		ft_error_exit("Error", "malloc");
	ft_init_values(pipex);
	ft_count_commands(argc, pipex);
	ft_allocate_pipes(pipex);
	ft_open_files(argc, argv, pipex);
	return (pipex);
}
