/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:54:44 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/08 20:54:33 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_open_files(int argc, char **argv, int *input, int *output)
{
	int	input_fd;
	int	output_fd;
	 //printf("\033[0;34mTrying to open files .....\033[0m\n");
	input_fd = ft_check_file(argv[1], O_RDONLY);
	output_fd = open(argv[argc-1], O_WRONLY | O_CREAT | O_TRUNC,0664);
	if (input_fd == -1 || output_fd == -1)
		 ft_perror_exit("\033[0;31mError with output_fd.\033[0m\n");
	//printf("\033[0;32mSuccessfully open file input : %d / output : %d.\033[0m\n",input_fd, output_fd);
	*input = input_fd;
	*output = output_fd;
}
