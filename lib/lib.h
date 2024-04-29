/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moun <yel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:38:41 by yel-moun          #+#    #+#             */
/*   Updated: 2024/04/29 15:59:07 by yel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*ft_strchr(char *s, int c);
int		ft_strlen(char *str);
int     ft_count_words(char *str);
int     ft_count_words_dil(char *str, char dil);
char    **ft_split_dil(char *str, char dil);
char	**ft_split(char *str);
char	*ft_strnstr(char *haystack, char *needle, int len);
void    ft_print(char *str, int fd);
void	ft_print_exit(char *str, int fd);
int     ft_is_space(char c);
void	ft_free_split(char **split, int c);
char	*ft_substr_dil(char *str, int start, char dil);
char	*ft_substr(char *str, int start);
int     ft_split_count(char  **split);

#endif