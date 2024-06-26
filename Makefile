# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgiurgev <dgiurgev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 01:19:25 by dgiurgev          #+#    #+#              #
#    Updated: 2024/04/15 18:41:51 by dgiurgev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME			=	client
SERVER_NAME			=	server
CLIENT_BONUS_NAME	=	client_bonus
SERVER_BONUS_NAME	=	server_bonus
CFLAGS				=	-Wall -Wextra -Werror
CC					=	cc
CLIENT_SRCS 		=	src/client.c
SERVER_SRCS 		=	src/server.c
CLIENT_BONUS_SRCS	=	src_bonus/client_bonus.c
SERVER_BONUS_SRCS	=	src_bonus/server_bonus.c
LIBFT				=	libft/libft.a
BIN					=	bin
OBJS				=	$(SRC:src/%.c=$(BIN)/%.o)

COLOR_RESET			=	\033[0m
COLOR_CYAN			=	\033[36m
COLOR_GREEN			=	\033[32m
COLOR_RED			=	\033[31m

all:					$(CLIENT_NAME) $(SERVER_NAME)
$(LIBFT):
						@cd libft && make
$(CLIENT_NAME):         $(CLIENT_SRCS) $(LIBFT)
						@ $(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) $(LIBFT)
$(SERVER_NAME):         $(SERVER_SRCS) $(LIBFT)
						@ $(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) $(LIBFT)

bonus:					$(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)
$(CLIENT_BONUS_NAME):   $(CLIENT_BONUS_SRCS) $(LIBFT)
						@ $(CC) $(CFLAGS) -o $@ $(CLIENT_BONUS_SRCS) $(LIBFT)
$(SERVER_BONUS_NAME):   $(SERVER_BONUS_SRCS) $(LIBFT)
						@ $(CC) $(CFLAGS) -o $@ $(SERVER_BONUS_SRCS) $(LIBFT)

$(BIN)/%.o:				src/%.c
						@mkdir -p $(BIN)
						@$(CC) $(CFLAGS) -c $< -o $@
						@echo "$(COLOR_GREEN)MINITALK Compilation completed: $@$(COLOR_RESET)"

clean:
						rm -f $(BIN)/*
						@echo "$(COLOR_RED)Cleanup completed.$(COLOR_RESET)"

fclean:					clean
						@rm -f $(NAME)
						@echo "$(COLOR_RED)Removal completed.$(COLOR_RESET)"

re:						fclean all

.PHONY:					all clean fclean re bonus
