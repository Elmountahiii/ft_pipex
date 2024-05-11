/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:54:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/11 11:19:01 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_open_files(int argc, char **argv, t_pipex *pipex)
{
	int		input_fd;
	int		output_fd;
	char	*error_file;
	
	input_fd = open(argv[1], O_RDONLY);
	output_fd = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC,0664);
	if (input_fd == -1 || output_fd == -1)
	{
		if (input_fd == -1)
			error_file = argv[1];
		else
			error_file = argv[argc - 1];
		free(pipex);
		ft_error_exit("no such file or directory", error_file);
	}
	pipex->input_file = input_fd;
	pipex->output_file = output_fd;
}
