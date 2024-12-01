# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -I./include

# Source files and object files
SRCS =	ft_printf.c math.c memory.c string.c \
		print_funcs/edge_funcs.c print_funcs/int_funcs.c print_funcs/str_funcs.c print_funcs/ptr_funcs.c \

OBJS =	$(SRCS:.c=.o)

# Target executable
NAME = libftprintf.a

# Build the program
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs  $(NAME) $(OBJS)

# Rule to clean object files
clean:
	rm -f $(OBJS)

# Rule to clean everything
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything
re: fclean all

# Specify dependencies
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY = re, clean, flcean