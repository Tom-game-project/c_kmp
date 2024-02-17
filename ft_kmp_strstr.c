#include <stdio.h>
#include <stdlib.h>

/*
* # ft_strlen
* 
* return length of string;
*/
unsigned int	ft_strlen(char *str)
{
	unsigned int count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

int	ft_streq(char *str0,char *str1,int stop_index)
{
	int i;

	i = 0;
	while (*str0 && i < stop_index)
	{
		if (*str0 != *str1)
			return (0);
		str0++;
		str1++;
		i++;
	}
	return (1);
}

/*
* # create_skip_list
* 
* create skip list and the pointer will return 
*/
int	*create_skip_list(char *str,unsigned int str_length)
{
	int *skip_list;
	unsigned int i;
	unsigned int slide;

	skip_list = malloc(sizeof(int) * str_length);
	if (!skip_list)
		return (NULL);
	i = 0;
	skip_list[i] = 1;
	i++;
	while (i < str_length)
	{
		slide = 1;
		while (slide < i && !ft_streq(&(str[slide]),str,i-slide))
			slide++;
		skip_list[i] = slide;
		i++;
	}
	return (skip_list);
}

/*
* # ft_strstr_test
* 
* return first matching pointer will return
*/
char	*ft_strstr(char *str,char *target)
{
	int *skip_list;
	unsigned int i;
	int j;
	unsigned int str_length;

	skip_list = create_skip_list(target,ft_strlen(target));
	str_length = ft_strlen(str);
	i = 0;
	while (i < str_length)
	{
		j = 0;

		while (target[j] != '\0')
		{
			j++;
			if (target[j] != str[i + j])
				break;
		}
		if (!target[j])
			return (&str[i]);
		i += skip_list[j];
	}
	return (&str[i]);
}

int	main(void)
{
	char *a = "abababbabcabbaaaaaa";
	char *target_a = "abcabba";

	printf("match %s\n", ft_strstr(a,target_a));
	return (0);
}

