CC	= gcc
MINILIBX	= minilibx_opengl/libmlx.a
NAME 		= so_long	
FLAGS		= -Wall -Wextra -Werror
OFLAGS		= -framework OpenGL -framework AppKit
SRCS 		= so_long.c
OBJS 		= $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(MINILIBX) $(OBJS)
	$(CC) $(OFLAGS) $(FLAGS) $(OBJS) -o $(NAME) minilibx_opengl/libmlx.a

$(MINILIBX):
	make -C minilibx

re: fclean all

clean:
	rm -rf $(OBJS)
fclean:
	rm -rf $(NAME)

git: 
	git add .
	git commit -m "$c"
	git push

.PHONY: clean run fclean re all git