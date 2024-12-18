CC := cc
CFLAGS := -Wall -Wextra -Werror # -Ofast
DEBUG_FLAGS := -g -O0
NAME := fdf

# .h files 
H_FILES := include/fdf.h

# .c files
SRC_DIR := srcs
vpath %.c $(SRC_DIR)
SRC_FILES := ft_add_point.c ft_check_key_presses.c ft_clear_img.c ft_connect_tiles.c ft_draw_fdf.c ft_draw_line.c ft_error.c ft_free_fdf_content.c ft_free_map_content.c ft_get_file_path.c ft_get_line_count.c ft_get_point.c ft_get_screen_middle_offset.c ft_hooks_setup.c ft_init_fdf.c ft_init_map.c ft_init_map_size.c ft_key_hook.c ft_loop.c ft_magnitude.c ft_normalize.c ft_on_resize.c ft_parse_map.c ft_point_in_area.c ft_print_map.c ft_print_point.c ft_put_pixel_save.c ft_reset_fdf_view.c ft_rotate.c ft_rotate_point.c ft_scale.c ft_scale_point.c ft_set_point.c ft_set_projection.c ft_subtract_point.c ft_update_fdf_img.c ft_zoom.c main.c projections.c

# .o files 
OBJ_DIR := obj
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# libft 
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

# libmlx 
LIBMLX_DIR := lib/MLX42
LIBMLX := $(LIBMLX_DIR)/build/libmlx42.a

# includes 
INCLUDES := -I include -I libft -I $(LIBMLX_DIR)/include
LIBS := $(LIBFT) $(LIBMLX)
LDFLAGS := -L$(LIBFT_DIR) -L$(LIBMLX_DIR)/build
LDLIBS := -ldl -lglfw -pthread -lm -lft -lmlx42

# all
all: $(NAME)

# libmlx
$(LIBMLX):
	cmake $(LIBMLX_DIR) -B $(LIBMLX_DIR)/build && make -C $(LIBMLX_DIR)/build -j4

# Regular Objs
$(NAME): $(OBJ_FILES) $(LIBS)
	$(CC) $(OBJ_FILES) $(LDFLAGS) $(LDLIBS) -o $(NAME)

# Compile OBJ_FILES
$(OBJ_DIR)/%.o: %.c $(H_FILES) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# clean 
clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) -r $(LIBMLX_DIR)/build
	$(MAKE) -C $(LIBFT_DIR) clean

# fclean
fclean:
	$(RM) -rf $(OBJ_DIR)
	$(RM) -rf $(LIBMLX_DIR)/build
	$(RM) -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# re
re: fclean all

# debug
debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

.PHONY: all clean fclean re debug libmlx
