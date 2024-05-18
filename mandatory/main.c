/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:58:05 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/18 13:58:13 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argc == 5)
		ft_pipex(argc, argv, env);
	else
	{
		ft_print("Error : bad arguments\n", 1);
		exit (1);
	}
	return (0);
}
