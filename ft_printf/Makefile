# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 11:45:57 by rtaboada          #+#    #+#              #
#    Updated: 2024/06/23 17:55:54 by rtaboada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a
LIBFTNAME 	= 	libft.a
INCLUDE		= 	ft_printf.h
	
LIBFTDIR	=	./libft
SRC			=	ft_printf.c			\
				ft_printf_utils.c	\
				ft_modifier_utils.c		\
				ft_puthex.c			\
				ft_putnbr.c			\
				ft_putnchar.c		\
				ft_putnbru.c		\
				ft_putptr.c			\
				ft_putstr.c			\
				ft_putchar.c		
	
OBJ			=	${SRC:.c=.o}
	
GCC			=	gcc
RM			=	rm -f
AR			=	ar rc
RN			=	ranlib



CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	makelibft $(OBJS) ${OBJ} 
	@echo "Compiling..."
	${AR} ${NAME} ${OBJ}
	${RN} ${NAME}
	@echo "Compilated successfully!"

clean:
	@echo "Removing *.o files..."
	${RM} ${OBJ}
	@cd $(LIBFTDIR) && make clean
	@echo "Done!"

fclean: clean
	@echo "Removing library..."
	${RM} $(NAME)
	@cd $(LIBFTDIR) && make fclean
	@echo "Done!"

re: fclean all  

.PHONY: all clean fclean re
