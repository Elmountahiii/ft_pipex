/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:05:02 by yel-moun          #+#    #+#             */
/*   Updated: 2024/05/08 20:53:34 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/pipex.h"

void check_leaks()
{
   system("leaks pipex");
}
int main(int argc, char **argv, char **env)
{
	if (argc == 5)
		ft_pipex(argc,argv,env);
	else
		return 1;
	return 0;
}
