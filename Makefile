# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/04 21:39:40 by mboukhal          #+#    #+#              #
#    Updated: 2022/03/23 19:00:43 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL		= all
NAME				= solong
INCLUDES			= -I /usr/local/include -I . -I libft/ \
					-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
TMP					= tmp/
LIBFT_PHAT			= libft/
CFILES				= $(NAME).c  file_analyzer.c game_start.c window_event.c \
					key_action.c 

CFLAGS				= -Wall -Wextra -Werror -g -fsanitize=address
RM					= rm -rf
LIB_EXT_MAKE 		= make $@ -C $(LIBFT_PHAT)

OBJ			= $(CFILES:.c=.o) 
clean:
	$(RM) $(OBJ) 
	$(LIB_EXT_MAKE)

fclean: clean
	$(RM) $(NAME)
	$(LIB_EXT_MAKE)
	

re: fclean all

.c.o:
	$(CC) $(CFLAGS) -c $<


$(NAME):$(OBJ)
	make -C $(LIBFT_PHAT)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT_PHAT)*.o $(INCLUDES) 

test_big: re clean
	@echo "test big map"
	@./$(NAME) m.ber

test2: re clean
	@echo "test map2 \n"
	@./$(NAME) map2.ber

test1: re clean
	@echo "test map1 \n"
	@./$(NAME) map1.ber

test_minim: re clean
	@echo "test extantion\n"
	@./$(NAME) map_mini.ber

test_extention: re clean
	./$(NAME) Makefile
	
all: $(NAME)

.PHONY: re fclean all clean run
