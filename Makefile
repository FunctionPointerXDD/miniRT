NAME:= miniRT
INCS:= miniRT.h
BNS_INCS:= miniRT_bonus.h

SRCS = src/main.c src/vec_utils.c src/parsing.c src/parse_utils.c src/mem_utils.c src/color.c src/parse_utils_2.c src/atof.c src/ray.c
BNS_SRCS = src_bonus/main_bonus.c

OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:.c=.o)

CC:=cc
DEBUG:= -g -fsanitize=address
CFLAGS:= -Wall -Wextra -Werror -O3
MFLAG:= -lmlx -framework OpenGL -framework AppKit -framework OpenGL
LIBFT = libft/libft.a
RM = rm -rf
MAKE = make 

all: $(NAME)

bonus : BONUS 

$(NAME): $(LIBFT) $(OBJS) $(INCS)
	$(CC) $(DEBUG) $(CFLAGS) $(OBJS) $(LIBFT) $(MFLAG) -o $@
	$(RM) BONUS

%.o: %.c
	$(CC) -g $(CFLAGS) -c $< -o $@

BONUS: $(LIBFT) $(BNS_OBJS) $(BNS_INCS)
	$(CC) $(CFLAGS) $(BNS_OBJS) $(LIBFT) $(MFLAG) -o $(NAME)
	touch $@

$(LIBFT):
	$(MAKE) -sC libft all

%.a: lib
	$(MAKE) $(@F) -C $(@D)

clean:
	$(RM) $(OBJS) $(BNS_OBJS) BONUS
	$(MAKE) -sC libft clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -sC libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
