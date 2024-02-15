# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 08:48:02 by hael-mou          #+#    #+#              #
#    Updated: 2023/10/24 20:36:15 by oezzaou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:=	cub3D

#=== Directories : =============================================================
SRC_DIR			:=	srcs
OBJ_DIR			:=	objs
GLFW_DIR		:=	$(shell brew --prefix glfw)
LIBFT_DIR		:=	libraries/libft
MLX42_DIR		:=	libraries/mlx42

#=== Libraries : ===============================================================
LIBFT			:=	$(LIBFT_DIR)/libft.a

#=== Files: ====================================================================
SRC_FILES		:=	$(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES		:=	$(patsubst %.c,$(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))
MAP_FILE		:=	"Default"

#=== include : =================================================================
INCLUDE_FILES	:=	$(wildcard libraries/*/includes/*.h) $(wildcard includes/*.h)
INCLUDE_DIRS	:=	$(sort $(dir $(INCLUDE_FILES)))

#=== Command : =================================================================
CC				:= 	cc
RM				:= 	rm -rf
CFLAGS 			:= 	-Wall -Wextra -Werror -o3 #-g -fsanitize=address
LINKS			:= 	-lmlx42 -lglfw -lft -lm
LINKS_DIR		:=	-L$(MLX42_DIR) -L$(GLFW_DIR)/lib -L$(LIBFT_DIR)
FRAMEWORKS		:=	-framework Cocoa -framework OpenGL -framework IOKit
INCLUDE			:=	$(addprefix -I,$(INCLUDE_DIRS))

#=== Colors : ==================================================================
DEF				:=	\033[3;39m
GRAY			:=	\033[3;90m
PINK			:=	\033[3;38;5;199m
RED				:=	\033[3;91m
GREEN			:=	\033[3;32m
CYAN			:=	\033[3;96m
PURPLE			:=	\033[3;35m
YELLOW			:=	\033[3;93m

#=== pattern rules : ===========================================================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]    $(PURPLE)Compiling  ==>  $(DEF)$<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]    $(PURPLE)Compiling  ==>  $(DEF)$<"

#=== role : ====================================================================
all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKS_DIR) $(FRAMEWORKS) $(OBJ_FILES) -o $@ $(LINKS)
	@echo "$(GREEN) [OK]    $(YELLOW)Creating   ==>  $(DEF)$(NAME) !!";

clean:
	@make -C $(LIBFT_DIR) clean
	@if [ -d $(OBJ_DIR) ]; then\
		$(RM) $(OBJ_DIR);\
		echo "$(GREEN) [OK]    $(RED)Removing   ==>  $(DEF)$(NAME) Object files";\
	fi

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@if [ -f $(NAME) ]; then\
		$(RM) $(NAME);\
		echo "$(GREEN) [OK]    $(RED)Removing   ==>  $(DEF)$(NAME)";\
	fi

re:	fclean all

bonus: all

run:
	@./$(NAME) $(MAP_FILE)

#=== Libraries cmp : ===========================================================
$(LIBFT):
	@make -C $(LIBFT_DIR)

#=== Create dir : ==============================================================
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.PHONY: all clean fclean re run
