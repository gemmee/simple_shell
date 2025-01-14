# **Simple Shell Project**

Welcome to the **Simple Shell** repository! This project is a custom implementation of a simple UNIX shell, created to deepen understanding of system calls, process management, and efficient programming practices.

---

## **Project Overview**
The **Simple Shell** provides a basic command-line interpreter with functionality similar to traditional shells. It supports interactive and non-interactive modes, environment management, command execution, and basic shell scripting features.

This project is an educational endeavor designed to solidify understanding of:
- System calls (`execve`, `fork`, etc.)
- Process control
- Memory management
- Building scalable, maintainable C programs

---

## **Features**
- Interactive and non-interactive modes.
- Execution of commands with and without arguments.
- PATH resolution for commands.
- Built-in commands such as `exit` and `env`.
- Custom handling for input (`getline` implementation).
- Support for semicolon (`;`), logical operators (`&&`, `||`), and comments (`#`).
- Environment variable management (`setenv`, `unsetenv`, `$?`, `$$`).
- Directory navigation using `cd`.
- Aliases for frequently used commands.
- File input support for batch processing.

---

## **Getting Started**

### **Requirements**
- **OS:** Ubuntu 20.04 LTS
- **Compiler:** GCC with flags `-Wall -Werror -Wextra -pedantic -std=gnu89`
- **Coding Style:** [Betty Style](https://github.com/holbertonschool/Betty/wiki)

### **Installation**
Clone the repository:
```bash
git clone https://github.com/username/simple_shell.git
cd simple_shell

