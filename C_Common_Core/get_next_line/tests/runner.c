#include "test_gnl.h"
#include "../get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char	*get_line(FILE *fp)
{
	char	*line;
	size_t	len;

	line = NULL;
	len = 0;
	if (getline(&line, &len, fp) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static int	compare_lines(char *got, char *expected)
{
	if (!got && !expected)
		return (1);
	if (!got || !expected)
		return (0);
	return (strcmp(got, expected) == 0);
}

int	run_test(char *filename)
{
	char	input[256];
	char	expected[256];
	int		fd;
	FILE	*fp;
	char	*got;
	char	*exp;
	int		line;

	snprintf(input, sizeof(input), "input/%s", filename);
	snprintf(expected, sizeof(expected), "expected/%s", filename);

	fd = open(input, O_RDONLY);
	if (fd < 0)
	{
		perror(input);
		return (0);
	}

	fp = fopen(expected, "r");
	if (!fp)
	{
		perror(expected);
		close(fd);
		return (0);
	}

	line = 1;
	while (1)
	{
		got = get_next_line(fd);
		exp = get_line(fp);

		if (!compare_lines(got, exp))
		{
			printf("❌ FAIL: %s (line %d)\n", filename, line);
			printf("Expected: %s", exp ? exp : "(NULL)\n");
			printf("Got:      %s", got ? got : "(NULL)\n");

			free(got);
			free(exp);
			close(fd);
			fclose(fp);
			return (0);
		}

		if (!got && !exp)
			break ;

		free(got);
		free(exp);
		line++;
	}

	close(fd);
	fclose(fp);

	printf("✅ PASS: %s\n", filename);
	return (1);
}
