LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS = ft_printf.c\
        sources/ft_char_treat.c \
        sources/ft_flag_treat.c \
        sources/ft_hexa_treat.c \
        sources/ft_int_treat.c \
        sources/ft_percent_treat.c \
        sources/ft_pointer_treat.c \
        sources/ft_putchar.c \
        sources/ft_putstrprec.c \
        sources/ft_string_treat.c \
        sources/ft_tolower_str.c \
        sources/ft_treatment.c \
        sources/ft_uint_treat.c \
        sources/ft_uitoa.c \
        sources/ft_ull_base.c \
        sources/ft_width_treat.c

SURPLU_O = ft_width_treat.o \
		   ft_treatment.o \
		   ft_uitoa.o \
		   ft_ull_base.o \
		   ft_putchar.o \
		   ft_tolower_str.o \
		   ft_putstrprec.o \
		   ft_string_treat.o \
		   ft_char_treat.o \
		   ft_pointer_treat.o \
		   ft_int_treat.o \
		   ft_uint_treat.o \
		   ft_percent_treat.o \
		   ft_hexa_treat.o \
		   ft_flag_treat.o

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = ${SRCS:.c=.o}

${NAME} : ${OBJS}
	${MAKE} bonus -C ./libft
	cp libft/libft.a ${NAME}
	${CC} ${FLAGS} ${INCLUDES} ${SRCS}
	ar -rcs ${NAME} ${OBJS}

all : ${NAME}

clean :
	${MAKE} clean -C ./libft
	rm -rf ${SURPLU_O}
	rm -rf ${OBJS}

fclean : clean
	${MAKE} fclean -C ./libft
	rm -rf ${NAME}

re : fclean all
