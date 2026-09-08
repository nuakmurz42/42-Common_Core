*This project has been created as part of the 42 curriculum by nuakmurz *

# get_next_line

## Description

`get_next_line` is a C project whose goal is to implement a function that reads and returns one line at a time from a file descriptor.

The function prototype is:

```c
char	*get_next_line(int fd);
```

Each call to `get_next_line()` returns the next available line, including the newline character `\n` when one is present.

The project teaches important C programming concepts such as:

* File descriptors
* The `read()` system call
* Static variables
* Dynamic memory allocation
* String manipulation
* Memory management
* End-of-file and error handling

## How It Works

The implementation uses a static string called `stash`.

The `stash` stores data that has already been read but has not yet been returned.

The general algorithm is:

1. Read data from the file descriptor into a temporary buffer.
2. Append the buffer to the existing stash.
3. Continue reading until a newline is found or the end of the file is reached.
4. Extract the first line from the stash.
5. Save the remaining characters in a new stash.
6. Return the extracted line.

Because the stash is declared as `static`, its value is preserved between different calls to `get_next_line()`.

## Project Files

```text
get_next_line.c
get_next_line_utils.c
get_next_line.h
```

### `get_next_line.c`

Contains the main logic of the project:

* Reading data from the file descriptor
* Extracting the next line
* Updating the stash
* Returning the next line

### `get_next_line_utils.c`

Contains helper functions used for string operations:

* `ft_strlen`
* `ft_find_newline`
* `ft_strjoin`

### `get_next_line.h`

Contains:

* Function prototypes
* Required library includes
* The default `BUFFER_SIZE` definition

## Instructions

### Compilation

Compile the project with a test file:

```bash
cc -Wall -Wextra -Werror \
get_next_line.c \
get_next_line_utils.c \
main.c
```

Run the program:

```bash
./a.out
```

### Custom BUFFER_SIZE

The buffer size can be changed during compilation:

```bash
cc -Wall -Wextra -Werror \
-D BUFFER_SIZE=10 \
get_next_line.c \
get_next_line_utils.c \
main.c
```

Examples:

```bash
-D BUFFER_SIZE=1
-D BUFFER_SIZE=42
-D BUFFER_SIZE=1000
```

The implementation should work correctly with different positive `BUFFER_SIZE` values.

## Usage Example

Example `main.c`:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

The returned line is dynamically allocated. The caller must free it after use:

```c
free(line);
```

## Return Values

`get_next_line()` returns:

* The next line when one is available
* The final line even if it does not end with `\n`
* `NULL` when the end of the file is reached
* `NULL` when an error occurs
* `NULL` when the file descriptor is invalid

## Important Technical Details

### Static Stash

The static stash preserves unread data between function calls.

For example, if one `read()` call produces:

```text
Hello\nWorld\n
```

the first call returns:

```text
Hello\n
```

and the remaining data:

```text
World\n
```

stays inside the stash for the next call.

### Null Terminator

The `read()` function does not automatically add a null terminator.

For this reason, the following operation is necessary:

```c
buffer[bytes] = '\0';
```

This allows the buffer to be safely used as a C string.

### Memory Management

Every dynamically allocated block must either:

* Be returned to the caller
* Be stored for the next function call
* Be freed when it is no longer required

The old stash is freed after its content is copied into a new memory allocation.

## Testing

Useful cases to test include:

* Empty file
* File containing one character
* File containing only a newline
* File containing several lines
* File ending with a newline
* File not ending with a newline
* Very long lines
* Consecutive newline characters
* Invalid file descriptor
* Different `BUFFER_SIZE` values

Example compilation with AddressSanitizer:

```bash
cc -Wall -Wextra -Werror \
-g3 -fsanitize=address \
get_next_line.c \
get_next_line_utils.c \
main.c
```

Example Valgrind command:

```bash
valgrind \
--leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
./a.out
```

## Resources

The following resources were used to understand the concepts required for this project:

* Linux manual page for `read()`:

```bash
man 2 read
```

* Linux manual page for `open()`:

```bash
man 2 open
```

* Linux manual page for `close()`:

```bash
man 2 close
```

* C documentation about dynamic memory allocation
* C documentation about static variables
* 42 project subject and peer discussions

## AI Usage

AI was used as a learning and debugging assistant during the project.

It was used for:

* Explaining file descriptors and the `read()` system call
* Understanding the purpose of a static stash
* Reviewing memory allocation and `free()` operations
* Explaining how lines and remaining data should be separated
* Identifying possible timeout and performance problems with very long lines
* Reviewing error handling and edge cases
* Asking evaluation-style questions to verify understanding of the implementation

AI-generated suggestions were reviewed and studied before being integrated. The final implementation was tested, analyzed, and adapted for the requirements of the project.
