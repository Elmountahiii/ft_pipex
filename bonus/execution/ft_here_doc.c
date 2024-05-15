/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:00:11 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 19:48:21 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_here_doc(t_pipex *pipex)
{
	char	*line;

	pipex->limiter = ft_strjoin(pipex->limiter, "\n");
	while (1)
	{
		ft_print("pipe heredoc> ", 1);
		line = get_next_line(0);
		if (!ft_strncmp(line, pipex->limiter, ft_strlen(line)))
		{
			free(line);
			break ;
		}
		ft_print(line, pipex->input_file);
		free(line);
	}
	close(pipex->input_file);
	pipex->input_file = open("/tmp/here_doc", O_RDWR);
}