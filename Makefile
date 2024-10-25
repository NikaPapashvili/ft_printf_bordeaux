# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npapashv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/22 23:56:54 by npapashv          #+#    #+#              #
#    Updated: 2024/10/24 04:19:22 by npapashv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS += -Wall -Wextra -Werror

SRC_MANDATORY  =	src/ft_printf.c \
					src/ft_format.c \

SRC_BONUS =			src_bonus/ft_printf_bonus.c \
					src_bonus/ft_format_bonus.c \
					src_bonus/ft_format_new.c \

MANAGEMENT_MANDATORY =	management/ft_manage_c.c \
						management/ft_manage_di.c \
						management/ft_manage_p.c \
						management/ft_manage_s.c \
						management/ft_manage_u.c \
						management/ft_manage_x.c \

MANAGEMENT_BONUS =	management_bonus/ft_manage_c.c \
					management_bonus/ft_manage_di.c \
					management_bonus/ft_manage_p.c \
					management_bonus/ft_manage_s.c \
					management_bonus/ft_manage_u.c \
					management_bonus/ft_manage_x.c \

UTILS =	utils/ft_atoi.c \
		utils/ft_isdigit.c \
		utils/ft_isflag.c \
		utils/ft_occ_c.c \
		utils/ft_putnbr_uns_base.c \
		utils/ft_putnchar.c \
		utils/ft_putnstr.c \
		utils/ft_strlen.c \


OBJ_MANDATORY  = $(SRC_MANDATORY:.c=.o) $(MANAGEMENT_MANDATORY:.c=.o) $(UTILS:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o) $(MANAGEMENT_BONUS:.c=.o) $(UTILS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_MANDATORY)
	ar rcs $(NAME) $(OBJ_MANDATORY)

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

clean:
	rm -f $(OBJ_MANDATORY) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
