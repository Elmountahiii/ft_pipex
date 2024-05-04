NAME = lib.a
HEADER = lib.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_strchr.c ft_strlen.c ft_split_dil.c  ft_count_words_dil.c ft_split.c ft_count_words.c  ft_is_space.c ft_strnstr.c ft_print.c \
ft_free_split.c ft_substr_dil.c ft_substr.c ft_print_exit.c ft_split_count.c ft_strjoin.c ft_join_three.c ft_strdup.c ft_is_quote.c \
ft_count_allocation.c ft_skip_space.c ft_skip_quotes.c ft_count_quote_allocation.c
OBJ = $(SRC:.c=.o)
RM = rm -rf
AR = ar rcs

%.o : %.c HEADER
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR)  $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all fclean clean re
