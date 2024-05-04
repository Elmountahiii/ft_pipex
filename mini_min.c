// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>
// #include <fcntl.h>
// # include <stdlib.h>
//  #include <sys/wait.h>

// int	ft_split_count(char  **split)
// {
// 	int	i;

// 	i = 0;
// 	while (split && split[i])
// 		i++;
// 	return (i);
// }


// void	ft_free_split(char **split, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (i < c)
// 	{
// 		free(split[i++]);
// 	}
// 	free(split);
// }


// int	ft_is_space(char c)
// {
// 	if (c == ' ' || c == '\t' || c == '\n')
// 		return (1);
// 	return (0);
// }
// int ft_is_quote(char c)
// {
// 	if (c == '\'' || c == '\"')
// 		return (1);
// 	return (0);
// }

//  char	*ft_substr(char *str, int start)
// {
// 	int		len;
// 	int		end;
// 	char	*sub;
// 	int		i;
// 	char	sign;

// 	i = 0;
// 	//printf("-start is :%d | str is %s \n",start,&str[start]);
// 	while (str[i + start])
// 	{
// 		 if (ft_is_quote(str[start]))
// 		 {
// 			sign = str[start++];
// 			while (str[i + start] && str[i + start] != sign)
// 				i ++;
// 			break;
// 		 }
// 		else if (ft_is_space(str[i + start]))
// 			break ;
// 		i ++;
// 	}
// 	end = start + i;
// 	len = end - start;
// 	i = 0;
// 	sub = malloc(sizeof(char) * (len + 1));
// 	if (!sub)
// 		return (NULL);
// 	while (str[i + start] && i < len)
// 	{
// 		sub[i] = str[i + start];
// 		i ++;
// 	}
// 	sub[i] = '\0';
// 	return (sub);
// }

// int	ft_count_words(char *str)
// {
// 	int	words;
// 	int i;
// 	int sign;

// 	i = 0;
// 	words = 0;
// 	while (str && str[i])
// 	{
// 		if (str[i] && ft_is_quote(str[i]))
// 		{
// 			sign = str[i++];
// 			while (str[i] && str[i] != sign)
// 			{
// 				i ++;
// 			}
// 			words ++;
// 			if (ft_is_quote(str[i]))
// 				i++;
// 		}else if (str[i] && !ft_is_space(str[i]) )
// 		{
// 			while (str[i] && !ft_is_space(str[i]))
// 				i++;
// 			words ++;	
// 		}
// 		else
// 			i ++;
	
// 	}
// 	return (words);
// }

// char	**ft_split(char *str)
// {
// 	char 	**split;
// 	int		index;
// 	int		i;

// 	split = malloc(sizeof(char *) * (ft_count_words(str) + 1));
// 	if (!split)
// 		return (NULL);
// 	i = 0;
// 	index = 0;
// 	while (str && str[i])
// 	{
// 		if (str[i] && (ft_is_quote(str[i]) || !ft_is_space(str[i])))
// 		{
// 			split[index] = ft_substr(str, i);
// 			if (!split[index])
// 				return (ft_free_split(split, index), NULL);
// 			index ++;
// 			if (str[i] && ft_is_quote(str[i]))
// 			{
// 				i++;
// 				while (str[i] && !ft_is_quote(str[i]))
// 					i ++;
// 				if (ft_is_quote(str[i]))
// 					i++;
// 			}
// 			else
// 			{
// 			while (str[i] && !ft_is_space(str[i]))
// 				i ++;
// 			}
// 		}
// 		else
// 			i++;
// 	}
// 	return (split[index] = NULL, split);
// }

// int main(int argc, char  *argv[])
// {
//    // printf("%s\n",argv[1]);
//   	char *str = "grep -v -a \"ls -la\"";
// 	printf("words count is : %d\n",ft_count_words(str));
//     char **split = ft_split(str);
//     int i = 0;
//     while (split[i])
//     {
//         printf("%s\n",split[i]);
//         i ++;
//     }
// 	//printf("split len : %d\n",i);
//     return 0;
// }