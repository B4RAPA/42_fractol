# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/16 09:49:13 by lfabel            #+#    #+#              #
#    Updated: 2024/06/18 15:41:19 by lfabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_strjoin.c ft_itoa.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_split.c ft_strnstr.c ft_substr.c
BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c ft_lstmap_bonus.c
OBJECT_FILES = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_strchr.o ft_strdup.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strrchr.o ft_strstr.o ft_tolower.o ft_toupper.o ft_strjoin.o ft_itoa.o ft_strtrim.o ft_strmapi.o ft_striteri.o  ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strnstr.o ft_substr.o 
OBJECT_FILES_BONUS = ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstclear_bonus.o ft_lstdelone_bonus.o ft_lstiter_bonus.o ft_lstlast_bonus.o ft_lstsize_bonus.o ft_lstadd_back_bonus.o ft_lstmap_bonus.o
HEADERS = libft.h


all: $(NAME)


$(NAME):
		cc -Wall -Wextra -Werror -I $(HEADERS) -c $(SRCS)
		ar -rcs $(NAME) $(OBJECT_FILES)

bonus:
		cc -Wall -Wextra -Werror -I $(HEADERS) -c $(BONUS)
		ar -rcs $(NAME) $(OBJECT_FILES_BONUS)

clean: 
		rm -rf $(OBJECT_FILES) $(OBJECT_FILES_BONUS)

fclean: clean
		rm -rf $(NAME)

re: 	fclean all

.PHONY: clean all flean re