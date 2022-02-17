NAME				:= 	philo_bonus

CC					:= 	gcc
RM					:= 	rm -rf

CFLAGS				=	-g -Wall -Wextra -Werror

HEADER				:= 	$(NAME).h

SRCS				:=	main.c \
						init.c \
						init_sem.c \
						philo_handler.c \
						death_handler.c \
						free_funs.c \
						time_funs.c \
						list_operations.c \
						error_check.c \
						ft_atoi.c \
						check_atoi_input.c \
						ft_itoa.c \
						ft_isdigit.c \
						ft_strlen.c \
						ft_calloc.c \

OBJS_DIR			:=	.objs/
OBJS				:=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:%.c=%.o)))

all:				$(NAME)

$(NAME):			$(OBJS_DIR) $(OBJS) Makefile
					$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS):			Makefile

$(OBJS_DIR)%.o:		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
					@mkdir -p $@

bonus:				all

clean:
					$(RM) $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
