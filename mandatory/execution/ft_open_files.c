/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:54:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/09 17:54:16 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_open_files(int argc, char **argv, int *input, int *output)
{
	int	input_fd;
	int	output_fd;
	input_fd = ft_check_file(argv[1], O_RDONLY);
	output_fd = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC,0664);
	if (output_fd == -1)
		ft_error_exit("no such file or directory", argv[argc-1]);
	*input = input_fd;
	*output = output_fd;
}
