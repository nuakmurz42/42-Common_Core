
#include <stdio.h>
#include <stdlib.h>

int ft_changer(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	*ft_range(int min, int max)
{
	int len = (max - min);
	len = ft_changer(len);
	len += 1;
	int i = 0;
	int *s;
        s = (int *) malloc(sizeof(int) * len);
	if (!s)
		return (NULL);
	if(min == max)
	{
		s[0] = 0;
		return (s);
	}
	if(max > min)
	{
		while (max >= min)
		{
			s[i] = max;
			max--;
			i++;
		}
	}
	else if(min > max)
	{
		while (min >= max)
		{
			s[i] = max;
			max++;
			i++;
		}
	}
	return (s);


}

int main(void)
{
	int i;
	int len;
	int *ptr = ft_range(0, 0);
		
	if (ptr == NULL)
	{
		printf("Hata");
		return (1);
	}
	len = sizeof(ptr);
	printf("%d\n", len);
	i = 0;
	while (i < len)
	{
		printf("%d ", ptr[i]);
		i++;
	}
	return (0);
}
