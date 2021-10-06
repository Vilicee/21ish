# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 13:58:33 by wvaara            #+#    #+#              #
#    Updated: 2021/10/06 16:55:32 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

FLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix $(SRCS_DIR)/, main.c ft_shell.c ft_echo.c \
	ft_read_until_matching_quote.c ft_save_input.c ft_check_quotation.c \
	ft_check_semic.c ft_dollar.c ft_which_command.c ft_search_env.c \
	ft_print_env.c ft_copy_env.c ft_setenv.c ft_write.c ft_unsetenv.c \
	ft_execve.c ft_extract_env_value.c ft_extract_command_path.c ft_cd.c \
	ft_dash_check.c ft_check_path.c ft_execute_cd.c ft_check_dot.c \
	ft_dotdot_slash.c ft_check_buf.c ft_dotdot.c ft_mini_echo.c \
	ft_path_parser.c ft_is_link.c ft_check_start.c ft_command_not_found.c \
	ft_is_quote.c ft_ignore.c ft_get_next_command.c ft_dollar_check.c \
	ft_check_echo_flag.c ft_echo_parser.c ft_command_parser.c ft_cd_parser.c \
	ft_new_dir.c ft_adhoc_split.c ft_find_echo_start.c ft_execve_with_pipes.c)
#	ft_which_quote.c

SRCS_DIR = srcs

OBJS_DIR = objs

OBJECTS = $(addprefix $(OBJS_DIR)/, main.o ft_shell.o ft_echo.o ft_read_until_matching_quote.o \
	ft_save_input.o ft_check_quotation.o ft_check_semic.o \
	ft_dollar.o ft_which_command.o ft_search_env.o ft_print_env.o \
	ft_copy_env.o ft_setenv.o ft_write.o ft_unsetenv.o ft_execve.o \
	ft_extract_env_value.o ft_extract_command_path.o ft_cd.o ft_dash_check.o \
	ft_check_path.o ft_execute_cd.o ft_check_dot.o ft_dotdot_slash.o \
	ft_check_buf.o ft_dotdot.o ft_mini_echo.o ft_path_parser.o ft_is_link.o \
	ft_check_start.o ft_command_not_found.o ft_is_quote.o ft_ignore.o \
	ft_get_next_command.o ft_dollar_check.o ft_check_echo_flag.o \
	ft_echo_parser.o ft_command_parser.o ft_cd_parser.o ft_new_dir.o \
	ft_adhoc_split.o ft_find_echo_start.o ft_execve_with_pipes.o)

INCLUDES = includes/

LIBRARIES = libft/libft.a libft/libftprintf.a

LIB_DIR = libft

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJECTS) $(LIBRARIES)
	gcc $(FLAGS) $(LIBRARIES) $(OBJECTS) -I $(INCLUDES) -o $(NAME)

$(LIBRARIES):
	$(MAKE) -C $(LIB_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	gcc -c $(FLAGS) $< -o $@ -I $(INCLUDES)

$(OBJS_DIR):
	mkdir objs

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

.Phony: all clean fclean re
