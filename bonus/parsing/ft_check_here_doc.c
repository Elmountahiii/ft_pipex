/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_here_doc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:03:05 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/14 21:42:09 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_check_here_doc(char *str, t_pipex *pipex)
{
	int	is_heredoc;
	
	is_heredoc = ft_strncmp(str, "here_doc", ft_strlen("here_doc"));
	if (is_heredoc == 0)
		pipex->is_here_doc = 1;
	else
		pipex->is_here_doc = 0;
}
