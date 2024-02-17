#include <stdio.h>

char *ft_strstr(char *str,char *target)
{
	char *str_ptr;
	char *target_ptr;

	while(*str)
	{
		str_ptr = str;
		target_ptr = target;
		while (*str_ptr == *target_ptr)
		{
			str_ptr++;
			target_ptr++;
		}
		if (!*target_ptr)
			return (str);
		str++;
	}
	return (str);
}

int main (void)
{
	char *a = "sunsunsurf";
	char *b;
	
	b = ft_strstr(a,"sunsurf");
	printf("%s\n",b);
}

