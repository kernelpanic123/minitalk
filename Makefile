# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abtouait <abtouait@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/26 08:50:45 by abtouait          #+#    #+#              #
#    Updated: 2025/04/26 10:21:00 by abtouait         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iprintf

SERVER = server
CLIENT = client

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

PRINTF_LIB = printf/libftprintf.a

all: $(SERVER) $(CLIENT) printf/libftprintf.a

$(SERVER): $(SERVER_OBJ) printf/libftprintf.a
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) printf/libftprintf.a

$(CLIENT): $(CLIENT_OBJ) printf/libftprintf.a
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) printf/libftprintf.a

$(PRINTF_LIB):
	make -C printf

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	make -C printf clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make -C printf fclean

re: fclean all

.PHONY: all clean fclean re