CC	= gcc -g
MINILIBX	= minilibx_opengl/libmlx.a
NAME 		= so_long	
FLAGS		= -Wall -Wextra -Werror
OFLAGS		= -framework OpenGL -framework AppKit
SRCS 		= $(wildcard src/*.c)
OBJS 		= $(SRCS:.c=.o) 

all : $(NAME)

$(NAME) : $(MINILIBX) $(OBJS) d
	$(CC) $(OFLAGS) $(FLAGS) $(OBJS) -o $(NAME) minilibx_opengl/libmlx.a Libft/libft.a

$(MINILIBX):
	make -C minilibx_opengl
d: 
	make -C Libft

re: fclean all

clean:
	rm -rf $(OBJS)
	rm -f minilibx_opengl/*.o
fclean: clean
	rm -rf $(NAME)
	rm -rf minilibx_opengl/*.a

git: 
	git add .
	git commit -m "$c"
	git push git@github.com:yeaktas/so_long.git

norm:
	norminette *.c
	norminette *.h

.PHONY: clean run fclean re all git d norm