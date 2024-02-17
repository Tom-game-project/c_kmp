#include <stdio.h>

char *ft_strstr(char *str,char *target);

int main (void)
{
	char *a = "abababbabcabbaaaaaa";
	char *target_a = "abcabba";

	printf("match %s\n", ft_strstr(a,target_a));
	return (0);
}