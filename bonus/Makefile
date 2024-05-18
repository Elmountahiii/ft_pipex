NAME = ../pipex_bonus
HEADER = pipex_bonus.h
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = main_bonus.c parsing/ft_get_path_bonus.c   \
 parsing/ft_check_path_bonus.c  execution/ft_execute_bonus.c  \
execution/ft_open_files_bonus.c   parsing/ft_count_command_bonus.c \
execution/ft_allocate_pipes_bonus.c execution/ft_init_struct_bonus.c execution/ft_pipex_bonus.c \
execution/ft_init_values_bonus.c \
execution/ft_clean_struct_bonus.c  execution/ft_init_heredoc_bonus.c parsing/ft_check_here_doc_bonus.c  \
execution/ft_here_doc_bonus.c 

OBJ = $(SRC:.c=.o)
RM = rm -rf

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	@cd .. && cd lib && make 
	$(CC) $(CFLAGS) $(OBJ) ../lib/lib.a -o $(NAME)

clean :
	$(RM) $(OBJ)
	$(RM) $(OBJ_TEST)
	@cd ..&& cd lib && make clean

fclean : clean
		$(RM) $(NAME) $(NAME_TEST)
		@cd .. && cd lib && make fclean

re :  fclean all 

.PHONY : all clean fclean re