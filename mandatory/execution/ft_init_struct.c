/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:42:10 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/12 13:51:43 by yel-moun        ###   ########.fr       */
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
	ft_extract_commands(argv, pipex);
	return (pipex);
}
