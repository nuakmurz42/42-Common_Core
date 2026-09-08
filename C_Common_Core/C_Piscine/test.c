#include <stdio.h>
#include <stdlib.h>
char *ft_strdup(char *str)
{
	char *s;
	int len;

	len = 0;
	while(str[len])
		len++;
	 s = malloc(sizeof(char) * (len + 1));
	 if(!s)
		 return (NULL);
	 len = 0;
	 while(str[len])
	 {
		 s[len] = str[len];
		 len++;
	 }
	 s[len]= '\0';
	return (s);
}

int main()
{
	char *ptr = ft_strdup("Selam");

	printf("%s\n" ,ptr);
	free(ptr);
	return (0);
}
