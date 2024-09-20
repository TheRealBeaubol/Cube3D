# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 16:43:41 by maldavid          #+#    #+#              #
#    Updated: 2024/05/03 12:34:49 by lboiteux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libmlx.so

SRCS		=  $(wildcard $(addsuffix /*.cpp, ./src/core))
SRCS		+= $(wildcard $(addsuffix /*.cpp, ./src/platform))
SRCS		+= $(wildcard $(addsuffix /*.cpp, ./src/renderer))
SRCS		+= $(wildcard $(addsuffix /*.cpp, ./src/renderer/**))

OBJ_DIR		= objs/makefile
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
FILE		=	$(shell ls -lR src/ | grep -F .cpp | wc -l)
PROJ_CMP	=	1
CXX			= clang++
CXXFLAGS	= -std=c++17 -O3 -fPIC -Wall -Wextra -Werror -DSDL_MAIN_HANDLED
INCLUDES	= -I./includes -I./src -I./third_party
RM			= @rm -rf
MK			= @mkdir -p

COLOR_1	= \033[1;38;5;28m
COLOR_2	= \033[1;38;5;120m
COLOR_3	= \033[1;38;5;240m
COLOR_4	= \033[1;38;5;255m
COLOR_5	= \033[1;38;5;248m
RESET	= \033[0m

$(OBJ_DIR)/%.o: %.cpp
	$(MK) $(@D)	
	@$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
	@if [ "$(PROJ_CMP)" -ne "$(FILE)" ]; then \
		printf " $(COLOR_1) [$(RESET)$(PROJ_CMP)$(COLOR_1)/$(RESET)$(FILE)$(COLOR_1)]\t$(RESET)$<                     \r"; \
	else \
		printf " $(COLOR_1) [$(RESET)$(PROJ_CMP)$(COLOR_1)/$(RESET)$(FILE)$(COLOR_1)]\t$(RESET)$<                 \n\n"; \
	fi
	@$(eval PROJ_CMP=$(shell echo $$(($(PROJ_CMP)+1))))

all:		$(NAME)

$(NAME): $(OBJS)
	@$(CXX) -shared -o $(NAME) $(OBJS) $(LDLIBS) 
	@printf "  ✅ $(COLOR_2)$(NAME) successfully compiled$(RESET)\n"
	@printf "  🔄 $(COLOR_3)$(NAME) is ready to run$(RESET) \n\n"

clean:
	@printf "  👾 \033[1;4;38;5;240m$(NAME)$(RESET)   \n  $(COLOR_3)└──> 🗑️    $(COLOR_4).o $(COLOR_5)have been deleted$(RESET)\n"	
	@$(RM) $(OBJ_DIR)
	
fclean:		clean
	@$(RM) $(NAME)
	@printf "  $(COLOR_3)└──> 🗑️    $(COLOR_4)$(NAME) binary $(COLOR_5)has been deleted$(RESET)\n\n"

re:			fclean all

.PHONY:		all clean fclean re