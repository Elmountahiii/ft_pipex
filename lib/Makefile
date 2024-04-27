NAME = lib.a
HEADER = lib.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_strchr.c ft_strlen.c ft_split.c ft_cont_words.c ft_is_space.c ft_strnstr.c ft_print.c \
ft_print_exit.c
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
