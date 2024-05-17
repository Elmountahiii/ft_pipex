NAME = pipex
HEADER = mandatory/pipex.h
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = mandatory/main.c  mandatory/parsing/ft_get_path.c  \
mandatory/parsing/ft_check_path.c  mandatory/execution/ft_execute.c  \
mandatory/execution/ft_open_files.c  mandatory/parsing/ft_count_command.c \
mandatory/execution/ft_allocate_pipes.c mandatory/execution/ft_init_struct.c \
mandatory/execution/ft_pipex.c mandatory/parsing/ft_extract_commands.c \
mandatory/execution/ft_init_values.c mandatory/execution/ft_clean_struct.c 
OBJ = $(SRC:.c=.o)
OBJ_TEST = $(SRC_TEST:.c=.o)
RM = rm -rf

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)


bonus :
	make -C bonus/


$(NAME) : $(OBJ)
	@cd lib && make
	$(CC) $(CFLAGS) $(OBJ) lib/lib.a -o $(NAME)

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJ_TEST)
	@cd lib && make clean
	@cd bonus && make clean

fclean : clean
		$(RM) $(NAME) $(NAME_TEST)
		@cd lib && make fclean
		@cd bonus && make fclean

re :  fclean all 

.PHONY : all clean fclean re bonus 