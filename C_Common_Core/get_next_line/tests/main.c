#include <stdio.h>
#include "test_gnl.h"

int main(void)
{
    char *tests[] = {
    "empty.txt",
    "one_line.txt",
    "many_lines.txt",
    "no_newline.txt",
    "only_newlines.txt",
    "long_line.txt",
    "spaces.txt",
    "single_char.txt",
    "many_lines_diff.txt",
    NULL
    };

    int i = 0;
    int passed = 0;

    while (tests[i])
    {
        passed += run_test(tests[i]);
        i++;
    }

    printf("\n%d/%d tests passed\n", passed, i);
}
