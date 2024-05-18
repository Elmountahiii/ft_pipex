/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:54:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/18 13:57:05 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_open_files(int argc, char **argv, t_pipex *pipex)
{
	char	*error_file;

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
