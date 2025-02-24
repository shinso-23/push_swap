NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = stack_op.c\
		stack_op_2.c\
		split.c\
		sort_small_num.c\
		sort_large_num.c\
		push_swap_utils.c\
		push_swap.c\
		free.c\

OBJS = $(SRCS:.c=.o)

ALL : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@ 

clean : 
		rm -rf $(OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean ALL

.Phony : ALL re clean fclean