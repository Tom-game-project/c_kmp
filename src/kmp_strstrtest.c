#include <stdio.h>

char	*kmp_strstr(char *str,char *target);

int	main(void)
{
	// test00
	char *text00 = "abababbabcabbaaaaaa";
	char *target00 = "abcabba";// default
	// test01
	char *text01 = "abababbabcabbaaaaaa";
	char *target01 = ""; //empty string
	// test02
	char *text02 = "abababbabcabbaaaaaa";
	char *target02 = "apple";

	char *text03 = "apple";
	char *target03 = "a";
	printf("match %s\n", kmp_strstr(text00,target00));
	printf("match %s\n", kmp_strstr(text01,target01));
	printf("match %s\n", kmp_strstr(text02,target02));
	printf("match %s\n", kmp_strstr(text03,target03));

	return (0);
}
