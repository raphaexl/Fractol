# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/07 16:36:00 by ebatchas          #+#    #+#              #
#    Updated: 2018/12/23 22:36:17 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=srcs
HEADDIR=includes
LIBDIR=libs

CFLAGS=-Wall -Wextra -Werror -I$(HEADDIR)
LDFLAGS=$(CFLAGS) -L$(LIBDIR) -lmlx -lft -lm -framework OpenGL -framework\
		AppKit

SRC=$(SRCDIR)/main.c\
	$(SRCDIR)/mlx_keycode.c\
	$(SRCDIR)/mlx_draw.c\
	$(SRCDIR)/input.c\
	$(SRCDIR)/tree.c\
	$(SRCDIR)/tools.c\
	$(SRCDIR)/complex.c\
	$(SRCDIR)/julia.c\
	$(SRCDIR)/fractol.c\
	$(SRCDIR)/thread.c\
	$(SRCDIR)/utils.c



OBJ=$(LIBDIR)/main.o\
	$(LIBDIR)/mlx_keycode.o\
	$(LIBDIR)/mlx_draw.o\
	$(LIBDIR)/input.o\
	$(LIBDIR)/tree.o\
	$(LIBDIR)/tools.o\
	$(LIBDIR)/julia.o\
	$(LIBDIR)/complex.o\
	$(LIBDIR)/fractol.o\
	$(LIBDIR)/thread.o\
	$(LIBDIR)/utils.o

NAME=fractol

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBDIR)/libft/ fclean && make -C $(LIBDIR)/libft
	cp $(LIBDIR)/libft/libft.a $(LIBDIR)
	$(CC) $(LDFLAGS) -o $@ $^

$(LIBDIR)/%.o:$(HEADDIR)/%.h

$(LIBDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY:clean fclean

clean:
	rm -rf $(LIBDIR)/*.o
	make -C $(LIBDIR)/libft clean

fclean:
	rm -rf $(NAME)
	make -C $(LIBDIR)/libft fclean

re: fclean all
