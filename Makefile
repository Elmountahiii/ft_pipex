NAME = pipex
HEADER = mandatory/pipex.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main.c mandatory/parsing/ft_check_file.c mandatory/parsing/ft_get_path.c  mandatory/parsing/ft_perror_exit.c \
 mandatory/parsing/ft_check_path.c  mandatory/execution/ft_execute.c
OBJ = $(SRC:.c=.o)
RM = rm -rf

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@cd lib && make
	$(CC) $(CFLAGS) $(OBJ) lib/lib.a -o $(NAME)

clean :
	$(RM) $(OBJ)
	@cd lib && make clean

fclean : clean
		$(RM) $(NAME)
		@cd lib && make fclean

re :  fclean all