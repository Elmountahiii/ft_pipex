/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmountahi <elmountahi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:37:59 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 15:17:22 by elmountahi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_open_files(int argc, char **argv, t_pipex *pipex)
{
	char	*error_file;
	
	if (pipex->is_here_doc)
	pipex->input_file = pipex->pipes[0][0];
	else
	pipex->input_file = open(argv[1], O_RDONLY);
	pipex->output_file = open(argv[argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (pipex->input_file == -1 || pipex->output_file == -1)
	{
		if (pipex->input_file == -1)
			error_file = argv[1];
		else
			error_file = argv[argc - 1];
		ft_clean_struct(pipex);
		ft_error_exit("no such file or directory", error_file);
	}
}
