/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmountahi <elmountahi@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:00:11 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 15:33:29 by elmountahi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_here_doc(t_pipex *pipex)
{
	char	*line;

	line = NULL;
	while (1)
	{
		ft_print("pipe heredoc> ", 1);
		line = get_next_line(0);
		if (!ft_strncmp(line, pipex->limiter, ft_strlen(pipex->limiter)))
		{
			free(line);
			break ;
		}
		ft_print(line, pipex->pipes[0][1]);
		free(line);
	}
	close(pipex->pipes[0][1]);
}