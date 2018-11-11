#include<stdio.h>
#include <stdlib.h>
//递归和非递归分别实现strlen
int strlen(char* string, int len)
{
	if (*(string+len) != '\0')
	{
		len++;
		strlen(string, len);
	}
	else
	{
		printf("%d", len);
	}
}
int main()
{
	char *string = "abcdef";
	int len = 0;
	strlen(string, len);
	system("pause");
}

//递归和非递归分别实现strlen
/*int strlen(char *string, int len)
{
	if (*(string + len))
	{
		len++;
		strlen(string, len);
	}
	else
	{
		printf("%d", len);
	}
}
void str(char *string)
{
	int len = 0;
	strlen(string, len);
}
int main()
{
	char *string = "ab";
	str(string);
	system("pause");
}*/