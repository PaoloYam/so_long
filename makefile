# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyammoun <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 10:40:50 by pyammoun          #+#    #+#              #
#    Updated: 2022/03/18 12:10:41 by pyammoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	${addprefix src/, so_long.c mapi.c start_game.c movement.c} \
		${addprefix get_next_line/, get_next_line.c get_next_line_utils.c}
OBJS        =	${SRCS:.c=.o}
NAME        =	so_long
AR    		=	ar rcs
GCC       	=	gcc 
RM       	=	rm -f
CFLAGS    	=	-Wall -Wextra -Werror -g -fsanitize=address 
MLX_PATH   	=	./mlx/
LBFT_PATH	=	./libft/
FRAMLIBS  	=    -L ${LBFT_PATH} -lft -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit

all:	$(NAME)

.c.o:
	$(GCC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME):    $(OBJS)
			@$(MAKE) -C $(LBFT_PATH)
			@$(MAKE) -C $(MLX_PATH)
			$(GCC) $(OBJS) $(CFLAGS) -I ${MLX_PATH} -I ${LBFT_PATH} -o $(NAME) $(FRAMLIBS)

clean:
	${RM} ${OBJS}
	@$(MAKE) -C $(LBFT_PATH) clean
	@$(MAKE) -C $(MLX_PATH) clean

fclean:        clean
	${RM} ${NAME}
	@$(MAKE) -C $(LBFT_PATH) fclean

re:			fclean all

.PHONY:		all clean fclean re
