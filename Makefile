NAME = pipex
LIB = libft

# Source files
SRC = source/main.c source/pipex.c source/path.c source/child.c
OBJ = $(SRC:.c=.o)

# Compiler flags
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g3 -fsanitize=address

# Test files
TEST_DIR = tests
BASIC_TEST = basic_test.sh
MULTI_TEST = multi_pipe_test.sh
HERE_DOC_TEST = here_doc_test.sh

# Colors for output
GREEN = \033[0;32m
YELLOW = \033[1;33m
RED = \033[0;31m
NC = \033[0m # No Color

.PHONY: all clean fclean re debug test help

# Default target
all: $(NAME)

# Main executable
$(NAME): $(OBJ)
		@make -C $(LIB) > /dev/null 2>&1
		@gcc $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)/libft.a
		@echo "$(GREEN)✓$(NC) $(NAME) compiled successfully!"

# Object files
source/%.o: source/%.c
		@gcc $(CFLAGS) -c $< -o $@

# Debug version with sanitizers
debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean $(NAME)
		@echo "$(YELLOW)⚠$(NC)  Debug build with address sanitizer enabled"

# Clean object files
clean:
		@rm -rf $(OBJ)
		@make -C $(LIB) clean > /dev/null 2>&1
		@echo "$(YELLOW)🧹$(NC) Object files cleaned"

# Clean everything including executable
fclean: clean
		@rm -rf $(NAME)
		@rm -rf $(TEST_DIR)
		@echo "$(YELLOW)🧹$(NC) All files cleaned"

# Rebuild everything
re: fclean all

# Test the program
test: $(NAME)
		@chmod +x $(TEST_DIR)/$(BASIC_TEST)
		@chmod +x $(TEST_DIR)/$(MULTI_TEST)
		@chmod +x $(TEST_DIR)/$(HERE_DOC_TEST)
		@echo "$(GREEN)🧪$(NC) Running tests..."
		@$(TEST_DIR)/$(BASIC_TEST)
		@$(TEST_DIR)/$(MULTI_TEST)
		@$(TEST_DIR)/$(HERE_DOC_TEST)
		@echo "$(GREEN)✓$(NC) All tests completed!"

# Create test directory and scripts
$(TEST_DIR):
		@mkdir -p $(TEST_DIR)

# Create test files
test-files: $(TEST_DIR)
		@echo "Creating test files..."
		@echo "Hello World\nThis is a test file\n42 is awesome" > $(TEST_DIR)/input.txt
		@echo -e "apple\nbanana\nApple\ncherry\nbanana\nApple" > $(TEST_DIR)/fruits.txt
		@echo "This is line 1\nThis is line 2" > $(TEST_DIR)/multiline.txt

# Help target
help:
		@echo "$(GREEN)Pipex Build System$(NC)"
		@echo ""
		@echo "Available targets:"
		@echo "  $(YELLOW)make$(NC)         - Build the main executable"
		@echo "  $(YELLOW)make debug$(NC)   - Build with debug flags and sanitizers"
		@echo "  $(YELLOW)make clean$(NC)   - Remove object files"
		@echo "  $(YELLOW)make fclean$(NC)  - Remove all generated files"
		@echo "  $(YELLOW)make re$(NC)      - Rebuild everything"
		@echo "  $(YELLOW)make test$(NC)    - Run test suite"
		@echo "  $(YELLOW)make help$(NC)    - Show this help message"
		@echo ""
		@echo "Usage examples:"
		@echo "  ./pipex input.txt \"cat\" \"wc -l\" output.txt"
		@echo "  ./pipex here_doc EOF \"cat\" \"tr 'a-z' 'A-Z'\" output.txt"
		@echo "  ./pipex input.txt \"grep error\" \"sort\" \"uniq -c\" output.txt"
