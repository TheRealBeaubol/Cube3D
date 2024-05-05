# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lboiteux <lboiteux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 22:20:43 by lboiteux          #+#    #+#              #
#    Updated: 2024/05/05 22:47:48 by mhervoch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# 								NAME PROJECT								   #
# **************************************************************************** #

NAME	=	cub3D

# **************************************************************************** #
# 								  COMMANDS									   #
# **************************************************************************** #

CC						=	@cc
CFLAGS					=	-Wall -Wextra -Werror -g
MK						=	@mkdir -p
FILE					=	$(shell ls -lR srcs/ | grep -F .c | wc -l)
PROJ_CMP				=	1
RM						= 	@rm -rf
IFLAGS					=	-I ./includes -I ./lib/MacroLibX/includes -I ./lib/libft/includes
LIBFT_NAME				= 	./lib/libft/libft.a
LIBFT_PATH				=	./lib/libft --no-print-directory 
MLX_NAME				= 	./lib/MacroLibX/libmlx.so
MLX_PATH				= 	./lib/MacroLibX --no-print-directory 

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

COLOR_1	= \033[1;38;5;28m
COLOR_2	= \033[1;38;5;120m
COLOR_3	= \033[1;38;5;240m
COLOR_4	= \033[1;38;5;255m
COLOR_5	= \033[1;38;5;248m
RESET	= \033[0m

# **************************************************************************** #
# 								   SOURCES									   #
# **************************************************************************** #

#SOURCES
SRCS	= 	main.c \
				exit.c \
				init.c \
				hook.c \
				print_map.c \

SRCS_DIR	:=	srcs
SRCS		:=	$(SRCS:%=$(SRCS_DIR)/%)

OBJS_DIR	:=	.objs
OBJS		:=	$(addprefix $(OBJS_DIR)/, $(SRCS:%.c=%.o))

$(OBJS_DIR)/%.o: %.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@
	@if [ "$(PROJ_CMP)" -ne "$(FILE)" ]; then \
		printf " $(COLOR_1) [$(RESET)$(PROJ_CMP)$(COLOR_1)/$(RESET)$(FILE)$(COLOR_1)]\t$(RESET)$<                     \r"; \
	else \
		printf " $(COLOR_1) [$(RESET)$(PROJ_CMP)$(COLOR_1)/$(RESET)$(FILE)$(COLOR_1)]\t$(RESET)$<                 \n\n"; \
	fi
	@$(eval PROJ_CMP=$(shell echo $$(($(PROJ_CMP)+1))))

all: $(MLX_NAME) $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
		@make -C $(LIBFT_PATH) -j

$(MLX_NAME):
		@make -C $(MLX_PATH) -j
		
$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(IGLAGS) $(OBJS) $(MLX_NAME) -lSDL2 -lm $(LIBFT_NAME) -o $(NAME) 
		@printf "  ✅ $(COLOR_2)$(NAME) successfully compiled$(RESET)\n"
		@printf "  🔄 $(COLOR_3)$(NAME) is ready to run$(RESET) \n\n"

clean:
		@printf "  👾 \033[1;4;38;5;240m$(NAME)$(RESET)   \n  $(COLOR_3)└──> 🗑️    $(COLOR_4).o $(COLOR_5)have been deleted$(RESET)\n"
		$(RM) $(OBJS_DIR)

fclean: clean
		$(RM) $(NAME)
		@printf "  $(COLOR_3)└──> 🗑️    $(COLOR_4)$(NAME) binary $(COLOR_5)has been deleted$(RESET)\n\n"
		@make fclean -C $(LIBFT_PATH) --no-print-directory -j
		@make fclean -C $(MLX_PATH) --no-print-directory -j



re:	fclean all

.PHONY:	re fclean all clean
