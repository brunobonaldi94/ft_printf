SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_printf_bonus.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

SRCS_LIBFT_PATH = ./libft/
LIBFT = libft.a
LIBFT_FULL_PATH = $(addprefix $(SRCS_LIBFT_PATH),$(LIBFT))

SRCS_UTILS_PATH = ./utils/

SRCS_UTILS_LIST_PATH = $(SRCS_UTILS_PATH)list_handler/
SRCS_UTILS_OPTIONS_PATH = $(SRCS_UTILS_PATH)format_options/
SRCS_PRINT_PATH = $(SRCS_UTILS_PATH)print_args/
SRCS_PRINT_PATH_HELPERS = $(SRCS_PRINT_PATH)print_helpers/

SRCS_UTILS_OPTIONS_FILES = format_options_handler.c format_options_helpers.c
SRCS_PRINT_PATH_FILE = print_args.c print_args_utils.c
SRCS_UTILS_LIST_FILE = format_linked_list.c
SRCS_PRINT_PATH_HELPERS_FILE = ft_print_percent.c ft_print_char.c ft_print_str.c \
				ft_print_int.c ft_print_uint.c ft_print_hex.c ft_print_ptr.c

SRCS_UTILS_MANDATORY =	$(addprefix $(SRCS_UTILS_OPTIONS_PATH), $(SRCS_UTILS_OPTIONS_FILES)) \
						$(addprefix $(SRCS_UTILS_LIST_PATH), $(SRCS_UTILS_LIST_FILE)) \
						$(addprefix $(SRCS_PRINT_PATH), $(SRCS_PRINT_PATH_FILE)) \
						$(addprefix $(SRCS_PRINT_PATH_HELPERS), $(SRCS_PRINT_PATH_HELPERS_FILE)) 

OBJS_UTILS_MANDATORY = $(SRCS_UTILS_MANDATORY:.c=.o)

SRCS_PRINT_PATH_FLAGS = $(SRCS_PRINT_PATH)flags_handler/
SRCS_PRINT_PATH_WIDTH = $(SRCS_PRINT_PATH)width_handler/

SRCS_UTILS_OPTIONS_FILES_BONUS =	format_options_handler_bonus.c format_options_helpers_bonus.c \
									format_options_invalid_bonus.c
SRCS_PRINT_PATH_FILE_BONUS =	print_args_bonus.c print_args_utils_bonus.c
SRCS_UTILS_LIST_FILE_BONUS = format_linked_list_bonus.c
SRCS_PRINT_PATH_HELPERS_FILE_BONUS = ft_print_percent_bonus.c ft_print_char_bonus.c ft_print_str_bonus.c \
				ft_print_int_bonus.c ft_print_uint_bonus.c ft_print_hex_bonus.c ft_print_ptr_bonus.c
SRCS_PRINT_PATH_FLAGS_FILE_BONUS = minus_zero_flag_handler_bonus.c
SRCS_PRINT_PATH_WIDTH_FILE_BONUS = width_handler_bonus.c

SRCS_UTILS_BONUS =	$(addprefix $(SRCS_UTILS_OPTIONS_PATH), $(SRCS_UTILS_OPTIONS_FILES_BONUS)) \
				$(addprefix $(SRCS_UTILS_LIST_PATH), $(SRCS_UTILS_LIST_FILE_BONUS)) \
				$(addprefix $(SRCS_PRINT_PATH), $(SRCS_PRINT_PATH_FILE_BONUS)) \
				$(addprefix $(SRCS_PRINT_PATH_HELPERS), $(SRCS_PRINT_PATH_HELPERS_FILE_BONUS)) \
				$(addprefix $(SRCS_PRINT_PATH_FLAGS), $(SRCS_PRINT_PATH_FLAGS_FILE_BONUS)) \
				$(addprefix $(SRCS_PRINT_PATH_WIDTH), $(SRCS_PRINT_PATH_WIDTH_FILE_BONUS))

OBJS_UTILS_BONUS = $(SRCS_UTILS_BONUS:.c=.o)


NAME = libftprintf.a
INCLUDES = ./includes

NAME_BONUS = libftprintf_bonus.a
INCLUDES_BONUS = ./includes_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RANLIB = ranlib
RM = rm -rf

%.o:	%.c
	$(CC) $(CFLAGS) -c -I$(INCLUDES) $< -o $(<:%.c=%.o)

all:	$(NAME)

bonus:	$(NAME_BONUS)

$(NAME):	$(LIBFT_FULL_PATH) $(OBJS) $(OBJS_UTILS_MANDATORY)
	cp $(LIBFT_FULL_PATH) ./
	mv $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS) $(OBJS_UTILS_MANDATORY)
	$(RANLIB) $(NAME)

%_bonus.o:	%_bonus.c
	$(CC) $(CFLAGS) -c -I$(INCLUDES_BONUS) $< -o $(<:%.c=%.o)

$(NAME_BONUS):	$(LIBFT_FULL_PATH) $(OBJS) $(OBJS_UTILS_MANDATORY) $(OBJS_BONUS) $(OBJS_UTILS_BONUS)
	cp $(LIBFT_FULL_PATH) ./
	mv $(LIBFT) $(NAME_BONUS)
	$(AR) $(NAME_BONUS) $(OBJS_BONUS) $(OBJS_UTILS_BONUS)
	$(RANLIB) $(NAME_BONUS)
	cp $(NAME_BONUS) $(NAME)

$(LIBFT_FULL_PATH):
	make -C $(SRCS_LIBFT_PATH) all

clean:
	$(RM) $(OBJS) $(OBJS_UTILS_MANDATORY) $(OBJS_BONUS) $(OBJS_UTILS_BONUS)
	make -C $(SRCS_LIBFT_PATH) clean

fclean:	clean
	$(RM) $(NAME) $(NAME_BONUS)
	make -C $(SRCS_LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus