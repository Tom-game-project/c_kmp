#include <stdio.h>
#include <strlib.h>

/*
* # ft_strlen
* 
* return length of string;
*/
unsigned int	ft_strlen(char *str)
{
	unsigned int count;

	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

/*
* # ft_strstr_test
* 
* return first matching pointer will return
*/
int	*ft_strstr_test(char *str,char *target)
{
	// kmp algorithum
	int *skip_list;

	skip_list = create_skip_list(str);
	return (skip_list);
}

/*
* int 
*/
int	ft_streq()
{
}

/*
* # create_skip_list
* 
* create skip list and the pointer will return 
*/
int	*create_skip_list(char *str)
{
	char *str_tmp;
	int *skip_list;
	int str_length;
	int i;
	int slide;

	str_tmp = str;
	str_length = ft_strlen(str);
	skip_list = malloc(sizeof(int) * str_length);
	if (!skip_list)
		return (NULL);
	i = 0;
	skip_list[i] = 1;
	i++;
	while (i < length)
	{
		slide = 1;
		
		skip_list[i] = ;
		i++;
	}
	return (skip_list);
}


int	main(void)
{
	char *a = "abababbabcabba";
	char *target = "abcabba";
	int string_length = ft_strlen(target);
	int *skip_list = create_skip_list(a);
	
	for (int i = 0; i<string_length; i++)
	{
		printf("%d\n",skip_list[i]);
	}
	return (0);
}

