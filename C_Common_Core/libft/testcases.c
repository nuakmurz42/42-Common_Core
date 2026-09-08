#include "libft.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#define RANDVAL(min, max) (rand() % ((max) - (min) + 1)) + (min)
#define ITERS 1000
#define TSTMSG(_M) (ft_putstrln("Testing function " #_M))
#define TSTFN(_FN_NAME) void test_##_FN_NAME() {\
    TSTMSG(_FN_NAME);\
    for (int _i = 0; _i < ITERS; _i++) {
#define TSTFN_END }\
    ft_putstrln("Function passed successfully");\
}

typedef void(*t_test_fn)(void);

static void ft_putstrln(char *str)
{
    size_t l = 0;
    while (str[l])
        l++;
    write(STDOUT_FILENO, str, l);
    write(STDOUT_FILENO, "\n", 1);
}

// Helper to fill a buffer with random printable characters and a null terminator
static void fill_rand_str(char *buf, size_t size) {
    if (size == 0) return;
    for (size_t i = 0; i < size - 1; i++) {
        buf[i] = (char)RANDVAL(32, 126);
    }
    buf[size - 1] = '\0';
}
// 1024 !! 1
// 1 !! 1
// 0 !! 0
// n, n!=0, !!, 1
TSTFN(isalpha)
    int c = RANDVAL(-255, 255);
    assert(!!ft_isalpha(c) == !!isalpha(c));
TSTFN_END

TSTFN(isdigit)
    int c = RANDVAL(-255, 255);
    assert(!!ft_isdigit(c) == !!isdigit(c));
TSTFN_END

TSTFN(tolower)
    unsigned char c = RANDVAL(-255, 255);
    assert((unsigned char)tolower(c) == (unsigned char)ft_tolower(c));
TSTFN_END

TSTFN(toupper)
    unsigned char c = RANDVAL(-255, 255);
    assert((unsigned char)toupper(c) == (unsigned char)ft_toupper(c));
TSTFN_END

TSTFN(memcpy)
    char memory[512];
    fill_rand_str(memory, 512);
    char memcpied[512], ft_memcpied[512];
    
    ft_bzero(memcpied, 512);
    ft_bzero(ft_memcpied, 512);
    
    size_t n = RANDVAL(0, 512);
    memcpy(memcpied, memory, n);
    ft_memcpy(ft_memcpied, memory, n);
    assert(!memcmp(memcpied, ft_memcpied, 512));
TSTFN_END

TSTFN(memset)
    char memsetted[512], ft_memsetted[512];
    int c = RANDVAL(0, 255);
    size_t n = RANDVAL(0, 512);
    
    memset(memsetted, c, n);
    ft_memset(ft_memsetted, c, n);
    assert(!memcmp(memsetted, ft_memsetted, n));
TSTFN_END

TSTFN(memmove)
    char memory_std[1024];
    char memory_ft[1024];
    fill_rand_str(memory_std, 1024);
    memcpy(memory_ft, memory_std, 1024);
    
    size_t offset = RANDVAL(0, 100);
    size_t n = RANDVAL(0, 500);
    
    memmove(memory_std + offset, memory_std, n);
    ft_memmove(memory_ft + offset, memory_ft, n);
    
    assert(!memcmp(memory_std, memory_ft, 1024));
TSTFN_END

TSTFN(strlcpy)
    char source_string[256];
    fill_rand_str(source_string, RANDVAL(10, 256));
    char copy[256], ft_copy[256];
    
    memset(copy, 'A', 256);
    memset(ft_copy, 'A', 256);
    
    size_t n = RANDVAL(0, 256);
    size_t copy_result = strlcpy(copy, source_string, n);
    size_t ft_copy_result = ft_strlcpy(ft_copy, source_string, n);
    
    assert(copy_result == ft_copy_result);
    assert(!memcmp(copy, ft_copy, 256));
TSTFN_END

TSTFN(strlcat)
    char src[256];
    fill_rand_str(src, RANDVAL(10, 256));
    char catt[512], ft_catt[512];
    
    fill_rand_str(catt, RANDVAL(10, 256));
    memcpy(ft_catt, catt, 512);
    
    size_t n = RANDVAL(0, 512);
    size_t catres = strlcat(catt, src, n);
    size_t ft_catres = ft_strlcat(ft_catt, src, n);
    
    assert(catres == ft_catres);
    assert(!memcmp(catt, ft_catt, 512));
TSTFN_END

TSTFN(strrchr)
    char src[512];
    fill_rand_str(src, 512);
    int c = RANDVAL(32, 126);
    assert(strrchr(src, c) == ft_strrchr(src, c));
TSTFN_END

TSTFN(strchr)
    char src[512];
    fill_rand_str(src, 512);
    int c = RANDVAL(32, 126);
    assert(strchr(src, c) == ft_strchr(src, c));
    assert(strchr(src, '\0') == ft_strchr(src, '\0'));
TSTFN_END

TSTFN(strncmp)
    char s1[512], s2[512];
    fill_rand_str(s1, RANDVAL(10, 512));
    
    if (RANDVAL(0, 1)) {
        memcpy(s2, s1, 512); 
    } else {
        fill_rand_str(s2, RANDVAL(10, 512));
    }
    
    size_t n = RANDVAL(0, 512);
    
    int res1 = strncmp(s1, s2, n);
    int res2 = ft_strncmp(s1, s2, n);
    
    // Standard library returns differ in magnitude, check sign parity
    assert((res1 > 0 && res2 > 0) || (res1 < 0 && res2 < 0) || (res1 == 0 && res2 == 0));
TSTFN_END

TSTFN(memchr)
    char src[512];
    fill_rand_str(src, 512);
    int c = RANDVAL(32, 126);
    size_t n = RANDVAL(0, 512);
    assert(memchr(src, c, n) == ft_memchr(src, c, n));
TSTFN_END

TSTFN(memcmp)
    char s1[512], s2[512];
    fill_rand_str(s1, 512);
    
    if (RANDVAL(0, 1)) {
        memcpy(s2, s1, 512);
    } else {
        fill_rand_str(s2, 512);
    }

    size_t n = RANDVAL(0, 512);
    int cres = memcmp(s1, s2, n);
    int ft_cres = ft_memcmp(s1, s2, n);
    
    assert((cres > 0 && ft_cres > 0) || (cres < 0 && ft_cres < 0) || (cres == 0 && ft_cres == 0));
TSTFN_END

TSTFN(strnstr)
    char s1[512], s2[32];
    fill_rand_str(s1, 512);
    
    if (RANDVAL(0, 1)) {
        // Guarantee a substring exists
        size_t start = RANDVAL(0, 480);
        strlcpy(s2, s1 + start, RANDVAL(2, 30));
    } else {
        // Totally random
        fill_rand_str(s2, RANDVAL(2, 30));
    }
    
    size_t n = RANDVAL(0, 512);
    // assert((char*)strnstr(s1, s2, n) == (char*)ft_strnstr(s1, s2, n));
TSTFN_END

TSTFN(atoi)
    char str[64];
    int sign = RANDVAL(0, 1) ? 1 : -1;
    long long val = (long long)RANDVAL(0, INT_MAX) * sign;
    sprintf(str, "%lld", val);
    
    // occasionally throw in whitespace or plus signs to test parser
    if (RANDVAL(0, 2) == 0) {
        sprintf(str, "   \t\v\f\r\n %s%lld", RANDVAL(0,1) ? "+" : "", val);
    }
    
    assert(atoi(str) == ft_atoi(str));
TSTFN_END

TSTFN(calloc)
    size_t count = RANDVAL(0, 100);
    size_t size = RANDVAL(0, 100);
    
    void *p1 = calloc(count, size);
    void *p2 = ft_calloc(count, size);
    
    if (count > 0 && size > 0) {
        assert(p1 != NULL && p2 != NULL);
        assert(!memcmp(p1, p2, count * size));
    }
    
    free(p1);
    free(p2);
TSTFN_END

TSTFN(strdup)
    char str[512];
    fill_rand_str(str, RANDVAL(1, 512));
    
    char *s1 = strdup(str);
    char *s2 = ft_strdup(str);
    
    assert(s1 != NULL && s2 != NULL);
    assert(strcmp(s1, s2) == 0);
    
    free(s1);
    free(s2);
TSTFN_END

TSTFN(substr)
    char source[256];
    fill_rand_str(source, RANDVAL(10, 256));
    
    unsigned int start = RANDVAL(0, 300); // Intentionally go out of bounds sometimes
    size_t len = RANDVAL(0, 300);
    
    char *nstr = ft_substr(source, start, len);
    assert(nstr != NULL);
    
    if (start < strlen(source)) {
        size_t expected_len = strlen(source + start);
        if (expected_len > len) expected_len = len;
        assert(strlen(nstr) == expected_len);
        assert(!strncmp(nstr, source + start, expected_len));
    } else {
        assert(strlen(nstr) == 0);
    }
    free(nstr);
TSTFN_END

// Helper functions for testing strmapi and striteri
static char mock_mapi(unsigned int i, char c) {
    return (i % 2 == 0) ? toupper(c) : tolower(c);
}

static void mock_iteri(unsigned int i, char *c) {
    if (i % 2 == 0) *c = toupper(*c);
    else *c = tolower(*c);
}

TSTFN(strjoin)
    char s1[128], s2[128];
    fill_rand_str(s1, RANDVAL(1, 128));
    fill_rand_str(s2, RANDVAL(1, 128));
    
    char *res = ft_strjoin(s1, s2);
    assert(res != NULL);
    assert(strlen(res) == strlen(s1) + strlen(s2));
    assert(!strncmp(res, s1, strlen(s1)));
    assert(!strcmp(res + strlen(s1), s2));
    
    free(res);
TSTFN_END

TSTFN(strtrim)
    char src[256];
    char set[16];
    fill_rand_str(src, RANDVAL(10, 256));
    fill_rand_str(set, RANDVAL(2, 16));
    
    char *res = ft_strtrim(src, set);
    assert(res != NULL);
    
    // Quick validation: Ensure bounds don't contain set characters
    if (strlen(res) > 0) {
        assert(strchr(set, res[0]) == NULL);
        assert(strchr(set, res[strlen(res) - 1]) == NULL);
    }
    free(res);
TSTFN_END

TSTFN(split)
    char src[256];
    fill_rand_str(src, RANDVAL(10, 256));
    char delim = (char)RANDVAL(32, 126);
    
    char **res = ft_split(src, delim);
    assert(res != NULL);
    
    for (int j = 0; res[j]; j++) {
        assert(strchr(res[j], delim) == NULL); // Substrings should not contain delimiters
        free(res[j]);
    }
    free(res);
TSTFN_END

TSTFN(itoa)
    int sign = RANDVAL(0, 1) ? 1 : -1;
    int val;
    if (RANDVAL(0, 10) == 0) {
        val = (RANDVAL(0, 1) ? INT_MIN : INT_MAX); // Edge cases
    } else {
        val = RANDVAL(0, INT_MAX) * sign;
    }
    
    char *res = ft_itoa(val);
    assert(res != NULL);
    assert(atoi(res) == val);
    free(res);
TSTFN_END

TSTFN(strmapi)
    char src[256];
    fill_rand_str(src, RANDVAL(10, 256));
    
    char *res = ft_strmapi(src, mock_mapi);
    assert(res != NULL);
    assert(strlen(res) == strlen(src));
    
    for (size_t j = 0; j < strlen(res); j++) {
        if (j % 2 == 0) assert(res[j] == toupper(src[j]));
        else assert(res[j] == tolower(src[j]));
    }
    free(res);
TSTFN_END

TSTFN(striteri)
    char src[256];
    char copy[256];
    fill_rand_str(src, RANDVAL(10, 256));
    strcpy(copy, src);
    
    ft_striteri(src, mock_iteri);
    
    for (size_t j = 0; j < strlen(src); j++) {
        if (j % 2 == 0) assert(src[j] == toupper(copy[j]));
        else assert(src[j] == tolower(copy[j]));
    }
TSTFN_END

TSTFN(putchar_fd)
    char buffer[2] = {0};
    char c = (char)RANDVAL(32, 126);
    
    int fd = open("test_putchar.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    ft_putchar_fd(c, fd);
    close(fd);

    fd = open("test_putchar.txt", O_RDONLY);
    read(fd, buffer, 1);
    close(fd);
    unlink("test_putchar.txt");

    assert(buffer[0] == c);
TSTFN_END

TSTFN(putstr_fd)
    char src[256];
    char buffer[256] = {0};
    fill_rand_str(src, RANDVAL(10, 255));
    
    int fd = open("test_putstr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    ft_putstr_fd(src, fd);
    close(fd);

    fd = open("test_putstr.txt", O_RDONLY);
    read(fd, buffer, 255);
    close(fd);
    unlink("test_putstr.txt");

    assert(strcmp(buffer, src) == 0);
TSTFN_END

TSTFN(putendl_fd)
    char src[256];
    char buffer[258] = {0};
    fill_rand_str(src, RANDVAL(10, 255));
    
    int fd = open("test_putendl.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    ft_putendl_fd(src, fd);
    close(fd);

    fd = open("test_putendl.txt", O_RDONLY);
    read(fd, buffer, 257);
    close(fd);
    unlink("test_putendl.txt");

    assert(strncmp(buffer, src, strlen(src)) == 0);
    assert(buffer[strlen(src)] == '\n');
TSTFN_END

TSTFN(putnbr_fd)
    char buffer[32] = {0};
    int sign = RANDVAL(0, 1) ? 1 : -1;
    int val = RANDVAL(0, INT_MAX) * sign;
    
    int fd = open("test_putnbr.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    ft_putnbr_fd(val, fd);
    close(fd);

    fd = open("test_putnbr.txt", O_RDONLY);
    read(fd, buffer, 32);
    close(fd);
    // unlink("test_putnbr.txt");
    
    assert(atoi(buffer) == val);
TSTFN_END

int main(void)
{
    srand((unsigned int)time(NULL)); // Seed RNG once for all tests

    test_isalpha();
    test_isdigit();
    test_memcpy();
    test_memset();
    test_memmove();
    test_strlcpy();
    test_strlcat();
    test_strrchr();
    test_strchr();
    test_tolower();
    test_toupper();
    test_strncmp();
    test_memchr();
    test_memcmp();
    test_strnstr();
    test_atoi();
    test_calloc();
    test_strdup();
    test_substr();
    test_strjoin();
    test_strtrim();
    test_split();
    test_itoa();
    test_strmapi();
    test_striteri();
    test_putchar_fd();
    test_putstr_fd();
    test_putendl_fd();
    test_putnbr_fd();
    
    return 0XDEADBEEF;
}