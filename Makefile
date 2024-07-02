NAME:= miniRT
INCS:= header/miniRT.h
BNS_INCS:= header_bonus/miniRT_bonus.h

SRCS = src/main.c src/vec_utils.c src/vec_utils_2.c src/parsing.c src/parse_utils.c \
    src/mem_utils.c src/color.c src/parse_utils_2.c src/atof.c src/ray.c \
    src/calculator.c src/check_col_all_cy.c src/check_col_all_pl.c \
    src/check_col_all_sp.c src/check_col_cy_side.c src/check_lit_col_all_cy.c \
    src/check_lit_col_all_pl.c src/check_lit_col_all_sp.c \
    src/get_cy_matrix.c src/get_view_matrix.c src/raytracer.c \
    src/relocate_to_view_space.c src/renderer.c src/calculator_2.c src/calculator_3.c \
    src/parse_utils_3.c

BNS_SRCS = src_bonus/main_bonus.c src_bonus/vec_utils_bonus.c src_bonus/vec_utils_2_bonus.c src_bonus/parsing_bonus.c src_bonus/parse_utils_bonus.c \
	src_bonus/mem_utils_bonus.c src_bonus/color_bonus.c src_bonus/parse_utils_2_bonus.c src_bonus/atof_bonus.c src_bonus/ray_bonus.c \
	src_bonus/calculator_bonus.c src_bonus/check_col_all_cy_bonus.c src_bonus/check_col_all_pl_bonus.c \
	src_bonus/check_col_all_sp_bonus.c src_bonus/check_col_cy_side_bonus.c src_bonus/check_lit_col_all_cy_bonus.c \
	src_bonus/check_lit_col_all_pl_bonus.c src_bonus/check_lit_col_all_sp_bonus.c \
	src_bonus/get_cy_matrix_bonus.c src_bonus/get_view_matrix_bonus.c src_bonus/raytracer_bonus.c \
	src_bonus/relocate_to_view_space_bonus.c src_bonus/renderer_bonus.c src_bonus/calculator_2_bonus.c src_bonus/calculator_3_bonus.c \
	src_bonus/parse_utils_3_bonus.c

OBJS = $(SRCS:.c=.o)
BNS_OBJS = $(BNS_SRCS:.c=.o)

CC:=cc
DEBUG:= -g -fsanitize=address
CFLAGS:= -Wall -Wextra -Werror -O3
MFLAG:= -lmlx -framework OpenGL -framework AppKit
LIBFT = libft/libft.a
RM = rm -rf
MAKE = make 

all: $(NAME)

bonus : BONUS 

$(NAME): $(LIBFT) $(OBJS) $(INCS)
	$(CC) $(DEBUG) $(CFLAGS) $(OBJS) $(LIBFT) $(MFLAG) -o $(NAME)
	$(RM) BONUS

%.o: %.c
	$(CC) -g $(CFLAGS) -c $< -o $@

BONUS: $(LIBFT) $(BNS_OBJS) $(BNS_INCS)
	$(CC) $(DEBUG) $(CFLAGS) $(BNS_OBJS) $(LIBFT) $(MFLAG) -o $(NAME)
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
