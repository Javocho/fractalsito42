# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/02 17:26:21 by fcosta-f          #+#    #+#              #
#    Updated: 2023/08/05 19:41:15 by fcosta-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Fractol
HEADER		= fract-ol.h

INCLUDE		= -I./inc -Iminilibx -Ilibft
SRCS_DIR 	= src
OBJ_DIR		= obj

SRCS		= $(wildcard $(SRCS_DIR)/*.c)
OBJS		= $(patsubst $(SRCS_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS		= $(addsuffix .d,$(basename ${OBJS}))
RUTAS		= minilibx/libmlx.a libft/libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O3 -g
RM			= rm -rf

######## COLORS #########
GREEN		= \033[1;92m
RED			= \033[1;91m
NC			= \033[0m

${OBJ_DIR}/%.o: ${SRCS_DIR}/%.c Makefile
	@mkdir -p ${OBJ_DIR}
	@${CC} -MT $@ ${CFLAGS} -MMD -MP ${INCLUDE} -c $< -o $@
	@echo "$(GREEN)Compiled: $<$(NC)"

all: ${NAME}

${NAME}: ${OBJS}
	@${MAKE} -C minilibx
	@${MAKE} -C libft
	${CC} ${CFLAGS} ${OBJS} ${RUTAS} -framework OpenGL -framework AppKit -o ${NAME}
	@echo "$(GREEN)$(NAME) compiled$(NC)"

-include ${DEPS}

clean:
	@${MAKE} clean -C minilibx
	@${MAKE} clean -C libft
	@rm -rf ${OBJ_DIR}
	@echo "$(RED)Cleaned up object files$(NC)"

fclean: clean
	@rm -rf ${NAME}
	@echo "$(RED)Removed executable: $(NAME)$(NC)"

re: fclean all

.PHONY: all clean fclean re
