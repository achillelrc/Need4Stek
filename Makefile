##
## Makefile for Makefile in /home/cracked/Delivery/CPE/Matchstick/CPE_2016_matchstick
## 
## Made by Choppy Thibaut
## Login   <cracked@epitech.net>
## 
## Started on  Wed Feb 22 16:10:50 2017 Choppy Thibaut
## Last update Sun Jun  4 21:36:20 2017 Choppy Thibaut
##

CC	=	gcc -Iinclude/

CFLAGS +=	-Wall

RM	=	rm -f

NAME	=	ai

SRC	=	./src/lib/putstr.c \
		./src/lib/stkstr.c \
		./src/lib/isfloat.c \
		./src/lib/str_to_wordtab.c \
		./src/lib/get_next_line.c \
		./src/scan.c \
		./src/move.c \
		./src/main.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
