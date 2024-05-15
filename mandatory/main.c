/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:05:02 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/15 22:36:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (argc == 5)
		ft_pipex(argc, argv, env);
	else
	{
		ft_print("Error : bad arguments\n", 2);
		exit (1);
	}
	return (0);
}
