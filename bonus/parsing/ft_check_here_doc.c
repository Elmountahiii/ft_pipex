/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_here_doc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:03:05 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/16 11:06:59 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	ft_check_here_doc(char *str, t_pipex *pipex)
{
	int	is_heredoc;

	if (ft_strlen(str) == 0)
	{
		pipex->is_here_doc = 0;
		return ;
	}
	is_heredoc = ft_strncmp(str, "here_doc", ft_strlen(str));
	if (is_heredoc == 0)
		pipex->is_here_doc = 1;
	else
		pipex->is_here_doc = 0;
}
