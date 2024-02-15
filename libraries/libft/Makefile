# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/07 08:48:02 by hael-mou          #+#    #+#              #
#    Updated: 2023/10/18 16:52:51 by hael-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:= libft.a

#=== Directories : ============================================================
SRC_DIR			:=	src
OBJ_DIR			:=	objs

#=== Files: ===================================================================
SRC_FILES		:=	$(wildcard $(SRC_DIR)/*/*.c)
OBJ_FILES		:=	$(patsubst %.c,$(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))

#=== include : ================================================================
INCLUDE_FILES	:= 	$(wildcard includes/*.h)
INCLUDE_DIRS	:=	$(sort $(dir $(INCLUDE_FILES)))

#=== Command : ================================================================
CC				:= 	cc
RM				:= 	rm -rf
CFLAGS 			:= 	-Wall -Wextra -Werror -o3 #-g -fsanitize=address
AR				:=	ar rc
INCLUDE			:=	$(addprefix -I,$(INCLUDE_DIRS))

#=== Colors : =================================================================
DEF				= \033[3;39m
GRAY			= \033[3;90m
PINK			= \033[3;38;5;199m
RED				= \033[3;91m
GREEN			= \033[3;32m
CYAN			= \033[3;96m
PURPLE			= \033[3;35m
YELLOW			= \033[3;93m

#=== pattern rules : ==========================================================
$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(GREEN) [OK]    $(PURPLE)Compiling  ==>  $(DEF)$(notdir $<)"

#=== role : ===================================================================
all: $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ_FILES)
	@$(AR) $@ $^
	@echo "$(GREEN) [OK]    $(YELLOW)Creating   ==>  $(DEF)libft !!";

clean:
	@if [ -d $(OBJ_DIR) ]; then\
		$(RM) $(OBJ_DIR);\
		echo "$(GREEN) [OK]    $(RED)Removing   ==>  $(DEF)libft  Object files";\
	fi

fclean: clean
	@if [ -f $(NAME) ]; then\
		$(RM) $(NAME);\
		echo "$(GREEN) [OK]    $(RED)Removing   ==>  $(DEF)$(NAME)";\
	fi

re: fclean all

#=== Create dir : =============================================================
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.PHONY: all clean fclean re
