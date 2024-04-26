NAME = pipex
HEADER = mandatory/pipex.h
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = main.c
OBJ = $(SRC:.c=.o)
RM = rm -rf

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@



all : $(NAME)

$(NAME) :  $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME)

re :  fclean all