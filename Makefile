##
## Makefile for pushswap in /home/dubus_b/rendu/C_Prog_Elem/CPE_2015_Pushswap
## 
## Made by Benjamin Dubus
## Login   <dubus_b@epitech.net>
## 
## Started on  Sun Nov 22 14:01:30 2015 Benjamin Dubus
## Last update Fri May 13 12:53:45 2016 Benjamin Dubus
##

CC		= gcc

RM		= rm -f

CFLAGS		+= -Wall -Wextra -Wpedantic -Werror

CLIENT		= client/client

SERVER		= server/server

SRCS_CLIENT	= client/source/main.c			\
		  client/source/useful_fonction.c

SRCS_SERVER	= server/source/main.c			\
		  server/source/main2.c			\
		  server/source/my_putchar.c		\
		  server/source/my_putnbr_uint.c	

OBJS1	= $(SRCS_CLIENT:.c=.o)

OBJS2	= $(SRCS_SERVER:.c=.o)


all: $(CLIENT) $(SERVER)

$(CLIENT): $(OBJS1)
	$(CC) -o $(CLIENT) $(OBJS1) 

$(SERVER): $(OBJS2)
	$(CC) -o $(SERVER) $(OBJS2) 
clean:
	 $(RM) $(OBJS1) $(OBJS2)

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
