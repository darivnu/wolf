##
## EPITECH PROJECT, 2024
## Makefile Day10
## File description:
## A cool makefile
##

# Project configuration
NAME = libmy
BIN = wolf3d
CC = gcc
CFLAGS = -Wall -Werror -ggdb -Iinc
REPLACE = -L./ -lmy -lcsfml-window -lcsfml-graphics -lcsfml-system \
-lcsfml-audio -lm
PROJECT = wolf3d
VERSION = 1.0

# Build information
BUILD_DATE = $(shell date '+%Y-%m-%d %H:%M:%S')
GIT_BRANCH = $(shell git rev-parse --abbrev-ref HEAD \
	2>/dev/null || echo "unknown")
GIT_COMMIT = $(shell git rev-parse --short HEAD \
	2>/dev/null || echo "unknown")
COMMIT_COUNT = $(shell git rev-list --count HEAD \
	2>/dev/null || echo "unknown")
REPO_URL = $(shell git config --get remote.origin.url \
	2>/dev/null || echo "unknown")
SYSTEM = $(shell uname -s)
ARCHITECTURE = $(shell uname -m)

# Source files
SOURCES = $(wildcard src/*.c)
L_SOURCES = $(wildcard lib/*.c)
OBJECTS = $(SOURCES:.c=.o)
L_OBJECTS = $(L_SOURCES:.c=.o)

# Source code statistics
SRC_COUNT = $(words $(SOURCES))
LIB_COUNT = $(words $(L_SOURCES))
TOTAL_COUNT = $(shell expr $(SRC_COUNT) + $(LIB_COUNT))
SRC_LINES = $(shell wc -l $(SOURCES) 2>/dev/null | \
	tail -n1 | awk '{print $$1}' || echo "unknown")
LIB_LINES = $(shell wc -l $(L_SOURCES) 2>/dev/null | \
	tail -n1 | awk '{print $$1}' || echo "unknown")
TOTAL_LINES = $(shell expr $(SRC_LINES) + $(LIB_LINES) \
	2>/dev/null || echo "unknown")

# Terminal colors
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
BOLD = \033[1m
RESET = \033[0m

# Main build
all: header library $(OBJECTS)
	@printf "$(GREEN)➜ Linking executable $(BIN)...$(RESET)\n"
	@$(CC) $(CFLAGS) -o $(BIN) $(OBJECTS) $(REPLACE)
	@printf "$(GREEN)✓ Build complete!$(RESET)\n"
	@printf "$(YELLOW)→ Run with: ./$(BIN)$(RESET)\n"

# Header display
header:
	@echo "$(MAGENTA)"
	@echo "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓"
	@echo "┃ ███╗   ███╗ █████╗ ██╗  ██╗███████╗███████╗██╗██╗     ███████╗ ┃"
	@echo "┃ ████╗ ████║██╔══██╗██║ ██╔╝██╔════╝██╔════╝██║██║     ██╔════╝ ┃"
	@echo "┃ ██╔████╔██║███████║█████╔╝ █████╗  █████╗  ██║██║     █████╗   ┃"
	@echo "┃ ██║╚██╔╝██║██╔══██║██╔═██╗ ██╔══╝  ██╔══╝  ██║██║     ██╔══╝   ┃"
	@echo "┃ ██║ ╚═╝ ██║██║  ██║██║  ██╗███████╗██║     ██║███████╗███████╗ ┃"
	@echo "┃ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝     ╚═╝╚══════╝╚══════╝ ┃"
	@echo "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\
$(RESET)"
	@echo "$(CYAN)Building $(TOTAL_COUNT) files ($(LIB_COUNT) lib, \
$(SRC_COUNT) prog)$(RESET)\n"

# Project info
info:
	@printf "$(CYAN)$(BOLD)+----------------------------------+$(RESET)\n"
	@printf "$(CYAN)$(BOLD)|      PROJECT INFORMATION         |$(RESET)\n"
	@printf "$(CYAN)$(BOLD)+----------------------------------+$(RESET)\n"
	@printf "$(YELLOW)  Project:   $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(PROJECT)"
	@printf "$(YELLOW)  Version:   $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(VERSION)"
	@printf "$(YELLOW)  Binary:    $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(BIN)"
	@printf "$(YELLOW)  Library:   $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(NAME)"
	@printf "$(YELLOW)  Built:     $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(BUILD_DATE)"
	@printf "$(CYAN)$(BOLD)+----------------------------------+$(RESET)\n"
	@printf "$(CYAN)$(BOLD)|      SOURCE CODE STATS           |$(RESET)\n"
	@printf "$(CYAN)$(BOLD)+----------------------------------+$(RESET)\n"
	@printf "$(YELLOW)  Lib Files: $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(LIB_COUNT)"
	@printf "$(YELLOW)  Prog Files:$(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(SRC_COUNT)"
	@printf "$(YELLOW)  Total:     $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(TOTAL_COUNT) files"
	@printf "$(YELLOW)  Lines:     $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(TOTAL_LINES)"
	@printf "$(CYAN)$(BOLD)+----------------------------------+$(RESET)\n"
	@printf "$(CYAN)$(BOLD)|      BUILD ENVIRONMENT           |$(RESET)\n"
	@printf "$(CYAN)$(BOLD)+----------------------------------+$(RESET)\n"
	@printf "$(YELLOW)  Compiler:  $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(CC)"
	@printf "$(YELLOW)  Flags:     $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(CFLAGS)"
	@printf "$(YELLOW)  OS:        $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(SYSTEM)"
	@printf "$(YELLOW)  Arch:      $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(ARCHITECTURE)"
	@printf "$(CYAN)$(BOLD)+----------------------------------+$(RESET)\n"
	@printf "$(CYAN)$(BOLD)|      GIT INFORMATION             |$(RESET)\n"
	@printf "$(CYAN)$(BOLD)+----------------------------------+$(RESET)\n"
	@printf "$(YELLOW)  Repo:      $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(REPO_URL)"
	@printf "$(YELLOW)  Branch:    $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(GIT_BRANCH)"
	@printf "$(YELLOW)  Commit:    $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(GIT_COMMIT)"
	@printf "$(YELLOW)  Count:     $(RESET)$(BOLD)%-20s$(RESET)\n" \
		"$(COMMIT_COUNT)"
	@printf "$(YELLOW)  Authors:   $(RESET)$(BOLD)\n$(RESET)"
	@git shortlog -sne 2>/dev/null | sed 's/^/    /' || \
		echo "    No Git repository found"
	@printf "$(CYAN)$(BOLD)+----------------------------------+$(RESET)\n"
	@printf "\n"
	@printf "$(GREEN)✓ Build:$(RESET) $(BOLD)make$(RESET)\n"
	@printf "$(GREEN)✓ Clean:$(RESET) $(BOLD)make clean$(RESET)\n"
	@printf "$(GREEN)✓ Help: $(RESET) $(BOLD)make help$(RESET)\n"

# Library building
library: $(L_OBJECTS)
	@printf "$(YELLOW)➜ Creating library $(NAME).a...$(RESET)\n"
	@ar -rc $(NAME).a $(L_OBJECTS)
	@printf "$(YELLOW)✓ Library built!$(RESET)\n\n"

# Compile rule
%.o: %.c
	@printf "$(BLUE)⟳ Compiling:$(RESET) $<\n"
	@$(CC) $(CFLAGS) -c $< -o $@

# Cleaning rules
clean:
	@printf "$(RED)➜ Cleaning objects...$(RESET)"
	@rm -f $(OBJECTS) $(L_OBJECTS)
	@printf "$(GREEN) Done!$(RESET)\n"

fclean: clean
	@printf "$(RED)➜ Removing binaries...$(RESET)"
	@rm -f $(NAME).a $(BIN)
	@printf "$(GREEN) Done!$(RESET)\n"

# Rebuild everything
re: fclean all

# Build and clean
comp: all clean

# Set special permissions
perm: all
	@printf "$(YELLOW)➜ Setting permissions...$(RESET)"
	@sudo chown root:root $(BIN)
	@sudo chmod u+s $(BIN)
	@printf "$(GREEN) Done!$(RESET)\n"

# Coding style check
cod: fclean
	@printf "$(CYAN)➜ Running coding-style check...$(RESET)\n"
	@coding-style . . > /tmp/coding_style_output.txt 2>&1 || true
	@if grep -q "coding style error" \
		/tmp/coding_style_output.txt; then \
		echo -n "$(RED)Errors: $(RESET)"; \
		grep "coding style error" \
			/tmp/coding_style_output.txt | \
			grep -o '[0-9]* coding style error' | \
			grep -o '[0-9]*'; \
		echo -n "$(RED)Major: $(RESET)"; \
		grep "coding style error" \
			/tmp/coding_style_output.txt | \
			grep -o '[0-9]* major' | \
			grep -o '[0-9]*'; \
		echo -n "$(YELLOW)Minor: $(RESET)"; \
		grep "coding style error" \
			/tmp/coding_style_output.txt | \
			grep -o '[0-9]* minor' | \
			grep -o '[0-9]*'; \
		echo -n "$(BLUE)Info: $(RESET)"; \
		grep "coding style error" \
			/tmp/coding_style_output.txt | \
			grep -o '[0-9]* info' | \
			grep -o '[0-9]*'; \
	else \
		echo "$(GREEN)No coding style errors found!$(RESET)"; \
	fi

# Help information
help:
	@printf "$(CYAN)AVAILABLE COMMANDS:$(RESET)\n"
	@printf "  $(YELLOW)make$(RESET)      - Build project\n"
	@printf "  $(YELLOW)make info$(RESET) - Show project info\n"
	@printf "  $(YELLOW)make clean$(RESET) - Remove objects\n"
	@printf "  $(YELLOW)make fclean$(RESET) - Full clean\n"
	@printf "  $(YELLOW)make re$(RESET)   - Rebuild from scratch\n"
	@printf "  $(YELLOW)make comp$(RESET) - Build and clean\n"
	@printf "  $(YELLOW)make perm$(RESET) - Set permissions\n"
	@printf "  $(YELLOW)make cod$(RESET)  - Check coding style\n"
	@printf "  $(YELLOW)make help$(RESET) - Show this help\n"

.PHONY: all header info library clean fclean re comp perm \
	cod help
