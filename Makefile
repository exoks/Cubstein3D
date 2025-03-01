#  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀                𓐓  Makefile 𓐔           
#  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
#  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀      Dev: oezzaou <oussama.ezzaou@gmail.com> 
#  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
#  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
#  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2023/09/07 08:48:02 by oezzaou
#  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/03/01 12:07:47 by oezzaou
#  ⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⣾⣿⣿⠿⠟⠛⠋⠛⢿⣿⣿⠻⣿⣿⣿⣿⡿⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⢠⣿⣟⣭⣤⣶⣦⣄⡀⠀⠀⠈⠻⠀⠘⣿⣿⣿⠇⠀                                              
#  ⠀⠀⠀⠀⠀⠱⠤⠊⠀⢀⣿⡿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠘⣿⠏⠀⠀                             𓆩♕𓆪      
#  ⠀⠀⠀⠀⠀⡄⠀⠀⠀⠘⢧⡀⠀⠀⠸⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠐⠋⠀⠀⠀                     𓄂 oussama ezzaou𓆃  
#  ⠀⠀⠀⠀⠀⠘⠄⣀⡀⠸⠓⠀⠀⠀⠠⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                              

#===<[ Clang compiler : ]>======================================================
CC            := cc
CFLAGS        := -Wall -Wextra -Werror
RM            := rm -rf

#===<[ Colors : ]>==============================================================
GREEN		      = \033[1;32m
RED		        = \033[1;31m
BLUE		      = \033[34m
CYAN		      = \033[1;36m
GRAY		      = \033[0;90m
PURPLE		    = \033[0;35m
YELLOW		    = \033[0;93m
BLACK  		    = \033[20m
MAGENTA 	    = \033[35m
WHITE  		    = \033[37m
PINK		      = \033[0;38;5;199m
ORANGE 		    = \033[38;5;214m
LIGHT_BLACK  	= \033[90m
LIGHT_RED    	= \033[91m
LIGHT_GREEN  	= \033[92m
LIGHT_YELLOW 	= \033[93m
LIGHT_BLUE   	= \033[94m
LIGHT_MAGENTA	= \033[95m
LIGHT_CYAN   	= \033[96m
LIGHT_WHITE  	= \033[97m
LIGHT_BLUE    = \033[38;5;45m
RESET         = \033[1;0m

#===<[ Sources : ]>=============================================================
PROJECT       := Cub3D
NAME          := cub3D
SRC_DIR       := src
OBJ_DIR       := obj
LIBFT         := libs/libft
MLX42         := libs/mlx42
MAP           := ./assets/maps/level1.cub
SRC           := $(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJ           := $(patsubst %.c,$(OBJ_DIR)/%.o, $(notdir $(SRC)))

INCLUDE_FILES := $(wildcard libs/*/include/*.h) $(wildcard include/*.h)
INCLUDE_DIRS	:= $(sort $(dir $(INCLUDE_FILES)))
INCLUDE       := $(addprefix -I,$(INCLUDE_DIRS))

#===[ Links: for MACOS ]===
GLFW_DIR      := $(shell brew --prefix glfw)
LINKS         := -lmlx42 -lglfw -lft -lm
LINKS_DIR     := -L$(MLX42) -L$(GLFW_DIR)/lib -L$(LIBFT)
FRAMEWORKS    := -framework Cocoa -framework OpenGL -framework IOKit

#===[ Links: for LINUX ]===
# LINKS       := -lmlx42 -lglfw -lft -lm
# LINKS_DIR   := -L$(MLX42) -L$(GLFW_DIR)/lib -L$(LIBFT)
# FRAMEWORKS  := -framework Cocoa -framework OpenGL -framework IOKit
# -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#===<[ Rules : ]>===============================================================
all: $(LIBFT) $(NAME)

$(NAME): $(OBJ_DIR) | $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKS_DIR) $(FRAMEWORKS) $| -o $@ $(LINKS)
	@echo | awk '{for (i=0; i < 80; i++)\
		{printf("$(GREEN)█"); system("sleep 0.01")}; printf("\n")}'
	@echo "${GREEN}[OK] ${CYAN}$@ ✔️${RESET}"

bonus: all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-38s| $@\n" "$<"

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-38s| $@\n" "$<"

$(LIBFT):
	@make -C $@ 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Rule usage > [ make run MAP=<map_file_path> ]
run:
	@./$(NAME) $(MAP)

clean:
	@make -s -C $(LIBFT) fclean
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

.PHONY: all bonus clean fclean re run $(LIBFT)
#===============================================================================
