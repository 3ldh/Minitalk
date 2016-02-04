##
## Makefile for minitalk in /home/sauvau_m/rendu/PSU_2015_minitalk
##
## Made by Mathieu Sauvau
## Login   <sauvau_m@epitech.net>
##
## Started on  Mon Feb  1 17:55:34 2016 Mathieu Sauvau
## Last update Thu Feb  4 19:35:25 2016 Mathieu Sauvau
##

CFLAGS += -W -Wall -Wextra
CFLAGS += -I./include/

SERVER = server

CLIENT = client

CLIENT_PATH = ./client/

SERVER_PATH = ./server/

UTILITIES = ./utilities/

SRC_CLIENT =	$(CLIENT_PATH)client.c \
		$(CLIENT_PATH)convertion.c \
		$(UTILITIES)my_getnbr.c \
		$(UTILITIES)function.c \
		$(UTILITIES)itoa.c \
		$(UTILITIES)my_revstr.c

SRC_SERVER =	$(SERVER_PATH)server.c \
		$(UTILITIES)my_put_nbr.c \
		$(UTILITIES)function.c \
		$(UTILITIES)my_getnbr.c \
		$(UTILITIES)my_strcat.c

OBJ_C = $(SRC_CLIENT:.c=.o)

OBJ_S = $(SRC_SERVER:.c=.o)

$(SERVER) : $(OBJ_S) $(CLIENT)
	gcc $(OBJ_S) -o $(SERVER_PATH)$(SERVER)

$(CLIENT) : $(OBJ_C)
	gcc $(OBJ_C) -o $(CLIENT_PATH)$(CLIENT)

all: $(SERVER)

clean:
	rm -f $(OBJ_C) $(OBJ_S)

fclean: clean
	rm -f $(SERVER_PATH)$(SERVER) $(CLIENT_PATH)$(CLIENT)

re: fclean all

.PHONY : all clean fclean re
