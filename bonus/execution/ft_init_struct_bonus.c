/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmountahi <elmountahi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:36:50 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 15:30:48 by elmountahi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

t_pipex	*ft_init_struct(int argc, char **argv, char **env)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		ft_error_exit("Error", "malloc");
	(void)env;
	ft_init_values(pipex);
	ft_init_heredoc(argv , pipex);
	ft_count_commands(argc, pipex);
	ft_allocate_pipes(pipex);
	ft_open_files(argc, argv, pipex);
	ft_extract_commands(argv, pipex);
	ft_validate_commands(env, pipex);
	ft_allocate_pid(pipex);
	return (pipex);
}
