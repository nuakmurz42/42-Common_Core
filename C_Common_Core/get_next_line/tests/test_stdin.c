#include "../get_next_line.h"

#include <stdlib.h>
#include <unistd.h>

static size_t	line_length(const char *line)
{
	size_t	length;

	length = 0;
	while (line[length] != '\0')
		length++;
	return (length);
}

int	main(void)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		write(STDOUT_FILENO, line, line_length(line));
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (0);
}
