*This project has been created as part of the 42 curriculum by nuakmurz .*

# Libft

## Description

Libft is the first project of the 42 curriculum. The goal of this project is to recreate a collection of standard C library functions and build a reusable static library. The project helps develop a solid understanding of pointers, memory management, strings, arrays, and linked lists in C.

## Library Description

The library contains utility functions implemented from scratch without using the original implementations from the standard C library.

### Character Functions

- ft_isalpha
- ft_isdigit
- ft_isalnum
- ft_isascii
- ft_isprint
- ft_toupper
- ft_tolower

### String Functions

- ft_strlen
- ft_strlcpy
- ft_strlcat
- ft_strchr
- ft_strrchr
- ft_strncmp
- ft_strnstr
- ft_strdup
- ft_substr
- ft_strjoin
- ft_strtrim
- ft_split
- ft_strmapi
- ft_striteri

### Memory Functions

- ft_memset
- ft_bzero
- ft_memcpy
- ft_memmove
- ft_memchr
- ft_memcmp
- ft_calloc

### Conversion Functions

- ft_atoi
- ft_itoa

### Output Functions

- ft_putchar_fd
- ft_putstr_fd
- ft_putendl_fd
- ft_putnbr_fd

### Linked List

The library also provides a generic singly linked list implementation.

Implemented functions:

- ft_lstnew
- ft_lstadd_front
- ft_lstsize
- ft_lstlast
- ft_lstadd_back
- ft_lstdelone
- ft_lstclear
- ft_lstiter
- ft_lstmap

These functions allow creating, traversing, modifying, deleting, and transforming linked lists while correctly managing dynamically allocated memory.

## Instructions

Compile the mandatory part:

```bash
make
```

Remove object files:

```bash
make clean
```

Remove object files and the library:

```bash
make fclean
```

Rebuild everything:

```bash
make re
```

The compilation generates the static library:

```text
libft.a
```

You can link it with your own C projects:

```bash
cc main.c libft.a
```

## Resources

### Documentation

- Linux man-pages Project: https://man7.org/linux/man-pages/
- The official 42 Libft subject
- Linux `man` pages

### AI Usage

Artificial intelligence was used only as a learning assistant.

It was used to:

- understand the behavior of standard C library functions;
- clarify concepts related to pointers, memory management, and linked lists;
- review the documentation and improve the README.

All functions in this library were implemented, tested, and fully understood by the author.
