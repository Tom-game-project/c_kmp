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

/*
* # ft_strstr_test
* 
* return first matching pointer will return
*/
/*
int	*ft_strstr_test(char *str,char *target)
{
	// kmp algorithum
	int *skip_list;

	skip_list = create_skip_list(str);
	return (skip_list);
}
*/


int	ft_streq(char *str0,char *str1,int stop_index)
{
	int i;

	i = 0;
	while (*str0 && i < stop_index)
	{
		if (*str0 != *str1)
		{
			return (0);
		}
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
int	*create_skip_list(char *str)
{
	int *skip_list;
	int str_length;
	int i;
	int slide;

	str_length = ft_strlen(str);
	skip_list = malloc(sizeof(int) * str_length);// list for return
	if (!skip_list)
		return (NULL);
	i = 0;
	skip_list[i] = 1;
	i++;
	while (i < str_length)
	{
		// i文字目で失敗したとき
		// どれくらい文字をずらせばいいのかを
		// 計算する
		slide = 1;
		printf("%d %s %s %d\n",i,&(str[slide]),str, i-slide);
		while (slide < i && !ft_streq(&(str[slide]),str,i-slide))
		{
			slide++;
			printf("%d %s %s %d\n",i,&(str[slide]),str, i-slide);
		}
		skip_list[i] = slide;
		i++;
	}
	return (skip_list);
}


int	main(void)
{
	char *a = "abababbabcabba";
	char *target = "abcabba";
 	unsigned int string_length = ft_strlen(target);
	int *skip_list = create_skip_list(target);

	printf("length of target %d\n", string_length);	
	for (unsigned int i = 0; i < string_length; i++)
	{
		printf("%d\n",skip_list[i]);
	}
	return (0);
}

