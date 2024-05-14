/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:05:19 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/14 11:33:42 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_init_heredoc(char **argv, t_pipex *pipex)
{
	ft_check_here_doc(argv[1], pipex);
	if (pipex->is_here_doc)
		pipex->limiter = argv[2];
	else
		pipex->limiter = NULL;
}
