NAME = pipex
NAME_TEST = test
HEADER = mandatory/pipex.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main.c mandatory/parsing/ft_check_file.c mandatory/parsing/ft_get_path.c   \
 mandatory/parsing/ft_check_path.c  mandatory/execution/ft_execute.c mandatory/execution/ft_replace_fd.c \
mandatory/execution/ft_open_files.c   mandatory/parsing/ft_count_command.c \
mandatory/execution/ft_allocate_pipes.c mandatory/execution/ft_init_struct.c mandatory/execution/ft_pipex.c \
mandatory/execution/ft_wait_children.c
SRC_TEST = test_main.c mandatory/parsing/ft_check_file.c mandatory/parsing/ft_get_path.c \
 mandatory/parsing/ft_check_path.c  mandatory/execution/ft_execute.c mandatory/execution/ft_replace_fd.c \
mandatory/execution/ft_open_files.c   mandatory/parsing/ft_count_command.c \
mandatory/execution/ft_allocate_pipes.c mandatory/execution/ft_init_struct.c mandatory/execution/ft_pipex.c \
mandatory/execution/ft_wait_children.c
OBJ = $(SRC:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)
RM = rm -rf

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

test : $(NAME_TEST)

$(NAME_TEST) : $(OBJ_TEST)
	@cd lib && make
	$(CC) $(CFLAGS) $(OBJ_TEST) lib/lib.a -o $(NAME_TEST)
	make clean

$(NAME) : $(OBJ)
	@cd lib && make
	$(CC) $(CFLAGS) $(OBJ) lib/lib.a -o $(NAME)
	make clean
clean :
	$(RM) $(OBJ)
	$(RM) $(OBJ_TEST)
	@cd lib && make clean

fclean : clean
		$(RM) $(NAME) $(NAME_TEST)
		@cd lib && make fclean

re :  fclean all