#include <stdlib.h>

/*
* # ft_strlen
* 
* return length of string;
*/
unsigned int	my_strlen(char *str)
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

int	streq(char *str0, char *str1, int stop_index)
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
		while (slide < i && !streq(&(str[slide]),str,i-slide))
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
char	*kmp_strstr(char *str,char *target)
{
	int *skip_list;
	unsigned int i;
	int j;
	int step;
	int ignore_step;
	unsigned int str_length;

	skip_list = create_skip_list(target,my_strlen(target));
	str_length = my_strlen(str);
	i = 0;
	ignore_step = 0;
	while (i < str_length)
	{
		j = ignore_step;

		while (target[j] != '\0')
		{
			j++;
			if (target[j] != str[i + j])
				break;
		}
		if (target[j] == '\0')
		{
			free(skip_list);
			return (&str[i]);
		}		
		step = skip_list[j];
		i += step;
		ignore_step = j - step;
	}
	free(skip_list);
	return (&str[i]);
}
