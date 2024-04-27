/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:38:41 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/27 15:00:31 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);
int     ft_count_words(char *str, char dil);
char	*ft_strnstr(char *haystack, char *needle, int len);
void    ft_print(char *str, int fd);
void	ft_print_exit(char *str, int fd);

#endif