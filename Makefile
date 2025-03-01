#  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀                𓐓  Makefile 𓐔           
#  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
#  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀      Dev: oezzaou <oussama.ezzaou@gmail.com> 
#  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
#  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
#  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2023/09/07 08:48:02 by oezzaou
#  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/03/01 10:50:20 by oezzaou
#  ⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⣾⣿⣿⠿⠟⠛⠋⠛⢿⣿⣿⠻⣿⣿⣿⣿⡿⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⢠⣿⣟⣭⣤⣶⣦⣄⡀⠀⠀⠈⠻⠀⠘⣿⣿⣿⠇⠀                                              
#  ⠀⠀⠀⠀⠀⠱⠤⠊⠀⢀⣿⡿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠘⣿⠏⠀⠀                             𓆩♕𓆪      
#  ⠀⠀⠀⠀⠀⡄⠀⠀⠀⠘⢧⡀⠀⠀⠸⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠐⠋⠀⠀⠀                     𓄂 oussama ezzaou𓆃  
#  ⠀⠀⠀⠀⠀⠘⠄⣀⡀⠸⠓⠀⠀⠀⠠⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                              

PROJECT		:= Cub3D
NAME 			:=	cub3D

#=== Directories : =============================================================
SRC_DIR			:=	src
OBJ_DIR			:=	obj
GLFW_DIR		:=	$(shell brew --prefix glfw)
LIBFT_DIR		:=	libs/libft
MLX42_DIR		:=	libs/mlx42

#=== Libraries : ===============================================================
LIBFT			:=	$(LIBFT_DIR)/libft.a

#=== Files: ====================================================================
SRC_FILES		:=	$(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES		:=	$(patsubst %.c,$(OBJ_DIR)/%.o, $(notdir $(SRC_FILES)))
MAP_FILE		:=	"Default"

#=== include : =================================================================
INCLUDE_FILES	:=	$(wildcard libs/*/include/*.h) $(wildcard include/*.h)
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
GREEN					= \033[1;32m
RED						= \033[1;31m
BLUE					= \033[34m
CYAN					= \033[1;36m
GRAY					= \033[0;90m
PURPLE				= \033[0;35m
YELLOW				= \033[0;93m
BLACK  				= \033[20m
MAGENTA 			= \033[35m
WHITE  				= \033[37m
PINK					= \033[0;38;5;199m
ORANGE 				= \033[38;5;214m
LIGHT_BLACK  	= \033[90m
LIGHT_RED    	= \033[91m
LIGHT_GREEN  	= \033[92m
LIGHT_YELLOW 	= \033[93m
LIGHT_BLUE   	= \033[94m
LIGHT_MAGENTA = \033[95m
LIGHT_CYAN   	= \033[96m
LIGHT_WHITE  	= \033[97m
LIGHT_BLUE		= \033[38;5;45m
RESET					= \033[1;0m

#=== role : ====================================================================
all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_DIR) | $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKS_DIR) $(FRAMEWORKS) $| -o $@ $(LINKS)
	@test | awk '{for (i=0; i < 80; i++)\
		{printf("$(GREEN)█"); system("sleep 0.01")}; printf("\n")}'
	@echo "${GREEN}[OK] ${CYAN}$@ ✔️${RESET}"

bonus: all

#=== Libraries cmp : ===========================================================
$(LIBFT):
	@make -C $(LIBFT_DIR)

#=== Create dir : ==============================================================
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

#=== pattern rules : ===========================================================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-38s| $@\n" "$<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-38s| $@\n" "$<"

clean:
	@make -s -C $(LIBFT_DIR) fclean
	@if [ -d $(OBJ_DIR) ]; then\
		${RM} $(OBJ_DIR);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-38s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(OBJ_DIR) ✔️";\
	else\
		printf "${RED}[KO]${RESET} ${BLUE}Not Found %-38s${RESET}| ./%s\n"\
					 "..." "$(PROJECT)/$(OBJ_DIR) ✖️";\
	fi

fclean: clean
	@if [ -f $(NAME) ]; then\
		${RM} $(NAME);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-38s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(NAME) ✔️";\
	else\
		printf "${RED}[KO]${RESET} ${BLUE}Not Found %-38s${RESET}| ./%s\n"\
					 "..." "$(PROJECT)/$(NAME) ✖️";\
	fi

re:	fclean all

.SUFFIXES: .c .o .a .so

.PHONY: all bonus clean fclean re run
#===============================================================================
