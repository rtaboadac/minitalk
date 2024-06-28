# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/24 11:45:57 by rtaboada          #+#    #+#              #
#    Updated: 2024/06/29 00:52:43 by rtaboada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVERNAME	=	server
CLIENTNAME	=	client
LIBFTNAME 	= 	libft.a
FTPRINTFNAME 	= 	libftprintf.a
INCLUDE		= 	server.h
	
LIBFTDIR	=	./libft
FTPRINTFDIR	=	./ft_printf
SERVERSRC	=	server.c	
	
OBJSERVER	=	${SERVERSRC:.c=.o}
	
GCC		=	gcc
RM		=	rm -f
AR		=	ar rc
RN		=	ranlib



CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

all: $(SERVERNAME)

makelibft:
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .

makeftprintf:			
	@make -C $(FTPRINTFDIR)
	@cp $(FTPRINTFDIR)/$(FTPRINTFNAME) .

.c.o:
	${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

compileserver:
	${GCC} ${CFLAGS} ${FTPRINTFNAME} ${SERVERSRC} -o ${SERVERNAME}

$(SERVERNAME):	makelibft makeftprintf $(OBJS) ${OBJ} 
	@echo "Compiling..."
	${AR} ${SERVERNAME} ${OBJ}
	${RN} ${SERVERNAME} 
	$(compileserver)
	@echo "Compilated successfully!"

clean:
	@echo "Removing *.o files..."
	${RM} ${OBJ}
	@cd $(LIBFTDIR) && make clean
	@cd $(FTPRINTFDIR) && make clean
	@echo "Done!"

fclean: clean
	@echo "Removing library..."
	${RM} $(NAME)
	@cd $(LIBFTDIR) && make fclean
	@cd $(FTPRINTFDIR) && make fclean
	@echo "Done!"

re: fclean all  

.PHONY: all clean fclean re
