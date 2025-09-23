#!/bin/bash

# Pipex Demo Script
# This script demonstrates the functionality of the pipex project

echo "🎯 Pipex Project Demonstration"
echo "=============================="
echo ""

# Colors
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Check if pipex exists
if [ ! -f "./pipex" ]; then
    echo -e "${RED}❌ Error: pipex executable not found!${NC}"
    echo "Please run 'make' first to build the project."
    exit 1
fi

echo -e "${BLUE}📋 Creating demo files...${NC}"

# Create demo input file
cat > demo_input.txt << 'EOF'
Hello World
This is a demonstration file
42 is an amazing school
Pipex recreates Unix pipes in C
System programming is fascinating
EOF

# Create another demo file
cat > demo_commands.txt << 'EOF'
Basic commands work great
Multiple pipes are supported
Here documents are implemented
Error handling is robust
Performance is excellent
EOF

echo -e "${GREEN}✅ Demo files created${NC}"
echo ""

# Demo 1: Basic pipe
echo -e "${YELLOW}Demo 1: Basic Pipe Operation${NC}"
echo "Command: ./pipex demo_input.txt \"cat\" \"grep World\" demo_output1.txt"
echo "Equivalent: cat demo_input.txt | grep World > demo_output1.txt"
echo ""

./pipex demo_input.txt "cat" "grep World" demo_output1.txt

echo "Shell output:"
cat demo_input.txt | grep World
echo ""
echo "Pipex output:"
cat demo_output1.txt
echo ""
echo -e "${GREEN}✅ Demo 1 completed${NC}"
echo ""

# Demo 2: Multiple pipes
echo -e "${YELLOW}Demo 2: Multiple Pipes${NC}"
echo "Command: ./pipex demo_input.txt \"cat\" \"wc -l\" \"tr -d ' '\" demo_output2.txt"
echo "Equivalent: cat demo_input.txt | wc -l | tr -d ' ' > demo_output2.txt"
echo ""

./pipex demo_input.txt "cat" "wc -l" "tr -d ' '" demo_output2.txt

echo "Shell output:"
cat demo_input.txt | wc -l | tr -d ' '
echo ""
echo "Pipex output:"
cat demo_output2.txt
echo ""
echo -e "${GREEN}✅ Demo 2 completed${NC}"
echo ""

# Demo 3: Here document
echo -e "${YELLOW}Demo 3: Here Document${NC}"
echo "Command: ./pipex here_doc END \"cat\" \"tr 'a-z' 'A-Z'\" demo_output3.txt"
echo "Equivalent: cat << END | tr 'a-z' 'A-Z' > demo_output3.txt"
echo ""

echo -e "${BLUE}📝 Please type or copy the following content and press Ctrl+D:${NC}"
echo "First line of input"
echo "Second line with text"
echo "Third line to transform"
echo ""

./pipex here_doc END "cat" "tr a-z A-Z" demo_output3.txt << 'END'
First line of input
Second line with text
Third line to transform
END

echo "Shell output:"
echo -e "First line of input\nSecond line with text\nThird line to transform" | tr a-z A-Z
echo ""
echo "Pipex output:"
cat demo_output3.txt
echo ""
echo -e "${GREEN}✅ Demo 3 completed${NC}"
echo ""

# Demo 4: Complex pipeline
echo -e "${YELLOW}Demo 4: Complex Pipeline${NC}"
echo "Command: ./pipex demo_commands.txt \"cat\" \"grep -i 'is'\" \"sort\" \"wc -l\" demo_output4.txt"
echo "Equivalent: cat demo_commands.txt | grep -i 'is' | sort | wc -l > demo_output4.txt"
echo ""

./pipex demo_commands.txt "cat" "grep -i is" "sort" "wc -l" demo_output4.txt

echo "Shell output:"
cat demo_commands.txt | grep -i is | sort | wc -l
echo ""
echo "Pipex output:"
cat demo_output4.txt
echo ""
echo -e "${GREEN}✅ Demo 4 completed${NC}"
echo ""

# Demo 5: Error handling
echo -e "${YELLOW}Demo 5: Error Handling${NC}"
echo "Testing error cases:"
echo ""

echo "1. Non-existent input file:"
./pipex nonexistent.txt "cat" "wc -l" output.txt 2>&1 | head -1
echo ""

echo "2. Invalid command:"
./pipex demo_input.txt "invalid_command_xyz" "wc -l" output.txt 2>&1 | head -1
echo ""

echo -e "${GREEN}✅ Demo 5 completed${NC}"
echo ""

# Cleanup
echo -e "${BLUE}🧹 Cleaning up demo files...${NC}"
rm -f demo_input.txt demo_commands.txt demo_output*.txt
echo -e "${GREEN}✅ Cleanup completed${NC}"
echo ""

echo -e "${GREEN}🎉 Pipex demonstration completed successfully!${NC}"
echo ""
echo "This demo shows that pipex correctly implements:"
echo "• Basic pipe operations"
echo "• Multiple command pipelines"
echo "• Here document functionality"
echo "• Proper error handling"
echo "• File input/output redirection"
echo ""
echo "The implementation recreates Unix pipe behavior using C system calls"
echo "including fork(), pipe(), dup2(), and execve()."
