#  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣦⣴⣶⣾⣿⣶⣶⣶⣶⣦⣤⣄⠀⠀⠀⠀⠀⠀⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢠⡶⠻⠛⠟⠋⠉⠀⠈⠤⠴⠶⠶⢾⣿⣿⣿⣷⣦⠄⠀⠀⠀                𓐓  Makefile 𓐔           
#  ⠀⠀⠀⠀⠀⢀⠔⠋⠀⠀⠤⠒⠒⢲⠀⠀⠀⢀⣠⣤⣤⣬⣽⣿⣿⣿⣷⣄⠀⠀                                              
#  ⠀⠀⠀⣀⣎⢤⣶⣾⠅⠀⠀⢀⡤⠏⠀⠀⠀⠠⣄⣈⡙⠻⢿⣿⣿⣿⣿⣿⣦⠀      Dev: oezzaou <oussama.ezzaou@gmail.com> 
#  ⢀⠔⠉⠀⠊⠿⠿⣿⠂⠠⠢⣤⠤⣤⣼⣿⣶⣶⣤⣝⣻⣷⣦⣍⡻⣿⣿⣿⣿⡀                                              
#  ⢾⣾⣆⣤⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇                                              
#  ⠀⠈⢋⢹⠋⠉⠙⢦⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇       Created: 2022/09/20 15:57:20 by oezzaou
#  ⠀⠀⠀⠑⠀⠀⠀⠈⡇⠀⠀⠀⠀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇       Updated: 2025/03/19 11:42:53 by oezzaou
#  ⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⢀⣾⣿⣿⠿⠟⠛⠋⠛⢿⣿⣿⠻⣿⣿⣿⣿⡿⠀                                              
#  ⠀⠀⠀⠀⠀⠀⠀⢀⠇⠀⢠⣿⣟⣭⣤⣶⣦⣄⡀⠀⠀⠈⠻⠀⠘⣿⣿⣿⠇⠀                                              
#  ⠀⠀⠀⠀⠀⠱⠤⠊⠀⢀⣿⡿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠘⣿⠏⠀⠀                             𓆩♕𓆪      
#  ⠀⠀⠀⠀⠀⡄⠀⠀⠀⠘⢧⡀⠀⠀⠸⣿⣿⣿⠟⠀⠀⠀⠀⠀⠀⠐⠋⠀⠀⠀                     𓄂 oussama ezzaou𓆃  
#  ⠀⠀⠀⠀⠀⠘⠄⣀⡀⠸⠓⠀⠀⠀⠠⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀                                              

#====<[ CC compiler: ]>=========================================================
CC			      = cc
CFLAGS	      = -Wall -Wextra -Werror
RM			      = rm -rf

#====<[ Colors: ]>==============================================================
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

#===<[ Sources: ]>==============================================================
PROJECT			  := libft
STATIC_LIB	  := libft.a
SHARED_LIB	  := libft.so
SRC_DIR			  := src
OBJ_DIR			  := obj
INCLUDE			  := -Iinclude 

SRC					  := $(wildcard */*/*.c) 
OBJ					  := $(addprefix $(OBJ_DIR)/, $(notdir ${SRC:.c=.o}))

#====<[ Rules: ]>===============================================================
all: static 

static: $(STATIC_LIB)

shared: $(SHARED_LIB)

$(STATIC_LIB): $(OBJ) 
	@ar -rcs $@ $^
	@echo "${GREEN}[OK] ${CYAN}$(STATIC_LIB) ✔️${RESET}"

$(SHARED_LIB): $(OBJ) 
	@$(CC) $(CFLAGS) -shared -o $@ $^  
	@echo "${GREEN}[OK] ${CYAN}$(SHARED_LIB) ✔️${RESET}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c | $(OBJ_DIR) 
	@$(CC) $(CFLAGS) $(INCLUDE) -fPIC -c $< -o $@
	@printf "$(GREEN)[OK]${RESET} ${PINK}Compiling${RESET} %-38s| $@\n" "$<"

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@if [ -d $(OBJ_DIR) ]; then\
		${RM} $(OBJ_DIR);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-38s${RESET}| ./%s\n"\
					 "... " "$(PROJECT)/$(OBJ_DIR) ✔️";\
	else\
		printf "${RED}[KO]${RESET} ${BLUE}Not Found %-38s${RESET}| ./%s\n"\
					 "..." "$(PROJECT)/$(OBJ_DIR) ✖️";\
	fi

fclean: clean
	@if [ -f $(STATIC_LIB) ]; then\
		${RM} $(STATIC_LIB);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-38s${RESET}| ./%s\n"\
				 "... " "$(PROJECT)/$(STATIC_LIB) ✔️";\
	elif [ ! -f $(STATIC_LIB) ]; then\
		printf "${RED}[KO]${RESET} ${BLUE}Not Found %-38s${RESET}| ./%s\n"\
					 "..." "$(PROJECT)/$(STATIC_LIB) ✖️";\
	fi
	@if [ -f $(SHARED_LIB) ]; then\
		${RM} $(SHARED_LIB);\
		printf "${GREEN}[OK]${RESET} ${ORANGE}Cleaning  %-38s${RESET}| ./%s\n"\
				 "... " "$(PROJECT)/$(SHARED_LIB) ✔️";\
	elif [ ! -f $(SHARED_LIB) ]; then\
		printf "${RED}[KO]${RESET} ${BLUE}Not Found %-38s${RESET}| ./%s\n"\
					 "..." "$(PROJECT)/$(SHARED_LIB) ✖️";\
	fi

re: fclean all

.SUFFIXES: .o .c .a .so 

.PHONY: all static shared clean fclean re
#===============================================================================
