# Pipex

[![42 School](https://img.shields.io/badge/42-Project-orange.svg)](https://42.fr)
[![C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

> A custom implementation of Unix pipes in C, recreating the functionality of shell pipe operator (`|`).

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Technical Details](#technical-details)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

**Pipex** is a project that recreates the behavior of the Unix pipe operator (`|`) in C. It demonstrates deep understanding of system programming concepts including:

- Process creation and management with `fork()`
- Inter-process communication using pipes
- File descriptor manipulation with `dup2()`
- Command execution with `execve()`
- Environment variable handling
- Error management

This project is part of the 42 curriculum and serves as an excellent learning tool for understanding Unix system calls and process management.

## ✨ Features

- **Basic piping**: `file1 cmd1 cmd2 file2`
- **Multiple pipes**: `file1 cmd1 cmd2 cmd3 ... cmdn file2`
- **Here document**: `here_doc LIMITER cmd1 cmd2 file2`
- **Robust error handling**
- **Path resolution** for command execution
- **Custom libft** library implementation

## 🚀 Installation

### Prerequisites

- GCC compiler
- Make build system
- Unix-like operating system (Linux/macOS)

### Building the Project

```bash
# Clone the repository
git clone https://github.com/migclay12/pipex.git
cd pipex

# Build the project
make

# The executable 'pipex' will be created in the root directory
```

### Cleaning Up

```bash
# Remove object files
make clean

# Remove executable and object files
make fclean

# Rebuild everything
make re
```

## 📖 Usage

### Basic Syntax

```bash
./pipex file1 cmd1 cmd2 file2
```

This is equivalent to: `< file1 cmd1 | cmd2 > file2`

### Multiple Commands

```bash
./pipex file1 cmd1 cmd2 cmd3 cmd4 file2
```

This is equivalent to: `< file1 cmd1 | cmd2 | cmd3 | cmd4 > file2`

### Here Document

```bash
./pipex here_doc LIMITER cmd1 cmd2 file2
```

This is equivalent to: `cmd1 << LIMITER | cmd2 > file2`

## 💡 Examples

### Example 1: Basic Text Processing
```bash
# Instead of: cat file.txt | grep "error" | wc -l > count.txt
./pipex file.txt "grep error" "wc -l" count.txt
```

### Example 2: Multiple Filters
```bash
# Instead of: cat access.log | grep "GET" | awk '{print $7}' | sort | uniq -c | sort -nr > top_pages.txt
./pipex access.log "grep GET" "awk '{print \$7}'" "sort" "uniq -c" "sort -nr" top_pages.txt
```

### Example 3: Here Document
```bash
# Instead of: echo -e "line1\nline2\nEOF" | cat | wc -l > count.txt
./pipex here_doc EOF "cat" "wc -l" count.txt
# Then type: line1
# line2
# EOF
```

## 🔧 Technical Details

### Process Architecture

1. **Parent Process**: Manages pipe creation and child process coordination
2. **Child Processes**: Each executes a specific command in the pipeline
3. **Pipe Communication**: Data flows through pipes between processes

### Key Functions

- `ft_pipex()`: Handles basic two-command pipelines
- `ft_pipex_bonus()`: Supports multiple command pipelines
- `ft_here_doc()`: Implements here document functionality
- `ft_join_path()`: Resolves command paths using PATH environment variable
- `ft_execve()`: Safely executes commands with proper error handling

### Memory Management

- Proper cleanup of allocated memory
- File descriptor management
- Process cleanup and exit handling

## 📁 Project Structure

```
pipex/
├── source/                 # Source code
│   ├── main.c             # Program entry point
│   ├── pipex.c            # Core pipex functionality
│   ├── path.c             # Path resolution logic
│   ├── child.c            # Child process management
│   └── pipex.h            # Header file with declarations
├── libft/                 # Custom C library
│   ├── ft_*.c            # Library functions
│   ├── libft.h           # Library header
│   └── Makefile         # Library build system
├── Makefile              # Main project Makefile
├── README.md             # This file
└── en.subject.pdf        # Project specification
```

## 📋 Requirements

This project implements the following requirements:

- ✅ Reproduce the behavior of `< file1 cmd1 | cmd2 > file2`
- ✅ Handle multiple pipes: `< file1 cmd1 | cmd2 | ... | cmdn > file2`
- ✅ Support here document: `cmd1 << LIMITER | cmd2 > file2`
- ✅ Proper error handling and usage messages
- ✅ No memory leaks
- ✅ Follow coding standards and norms

## 🧪 Testing

### Basic Tests

```bash
# Test basic functionality
echo "Hello World" > input.txt
./pipex input.txt "cat" "wc -c" output.txt
cat output.txt  # Should show character count

# Compare with shell pipe
echo "Hello World" | cat | wc -c
```

### Multiple Commands Test

```bash
# Test multiple pipes
echo -e "apple\nbanana\nApple\ncherry" > fruits.txt
./pipex fruits.txt "grep Apple" "sort" "uniq -c" result.txt

# Equivalent shell command
cat fruits.txt | grep Apple | sort | uniq -c
```

### Here Document Test

```bash
# Test here document
./pipex here_doc EOF "cat" "tr 'a-z' 'A-Z'" uppercase.txt
# Type: hello world
# EOF
cat uppercase.txt  # Should show "HELLO WORLD"
```

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request. For major changes, please open an issue first to discuss what you would like to change.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📚 Learning Outcomes

This project demonstrates mastery of:

- **System Programming**: Unix system calls, process management
- **File I/O**: File descriptors, redirection, pipes
- **Process Management**: Fork, exec, wait system calls
- **Error Handling**: Robust error detection and reporting
- **Memory Management**: Dynamic allocation and cleanup
- **Shell Internals**: Understanding of how shells work internally

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Miguel Gonzalez Clayton**
- 42 School Student

---

> "The best way to learn system programming is by implementing system tools yourself."

*Made with ❤️ for the 42 curriculum*
