NAME = pipex

HEADER = pipex_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -g  
SRC = main_bonus.c parsing/ft_check_file_bonus.c parsing/ft_get_path_bonus.c   \
 parsing/ft_check_path_bonus.c  execution/ft_execute_bonus.c execution/ft_replace_fd_bonus.c \
execution/ft_open_files_bonus.c   parsing/ft_count_command_bonus.c \
execution/ft_allocate_pipes_bonus.c execution/ft_init_struct_bonus.c execution/ft_pipex_bonus.c \
execution/ft_check_commands_bonus.c parsing/ft_extract_commands_bonus.c \
parsing/ft_validate_commands_bonus.c execution/ft_allocate_pId_bonus.c execution/ft_init_values_bonus.c \
execution/ft_clean_struct_bonus.c  execution/ft_init_heredoc.c parsing/ft_check_here_doc.c  parsing/ft_debug.c \
execution/ft_here_doc.c


OBJ = $(SRC:.c=.o)
RM = rm -rf

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@cd .. && cd lib && make 
	$(CC) $(CFLAGS) $(OBJ) ../lib/lib.a -o $(NAME)
	make clean

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJ_TEST)
	@cd ..&& cd lib && make clean

fclean : clean
		$(RM) $(NAME) $(NAME_TEST)
		@cd .. && cd lib && make fclean

re :  fclean all 

.PHONY : all clean fclean re