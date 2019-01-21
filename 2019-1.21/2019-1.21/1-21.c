#include<stdio.h>                                                                                                                                                                            
#include<assert.h>
#include<string.h>
//char *Strtok(char * str,const char *delimiters)
//{
//  char *p = str;
//  while(*str != '\0')
//  {
//    if(*str == *delimiters)
//    {
//      *str = '/0';
//      return p;
//    }
//    str++;
//  }
//}
//int main()
//{
//  char arr[] = "wo yi ma dang xian";
//  char *p= strtok(arr," "); 
//  while(p != NULL)
//  {
//    printf("%s\n",p);
//    p = strtok(NULL," ");
//  }
//}
const char *Strchr(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == character)
		{
			{
				return str;
			}
			str++;
		}
		W>
	}
	int main()
	{
		char arr[] = "wo yi ma dang xian";
		const char *pch;
		printf("looking for the 'a' character in %s\n", arr);
		pch = Strchr(arr, 'a');
		while (pch != NULL)
		{
			W>    printf("'a'found at %d\n", pch - arr + 1);
			pch = Strchr(pch + 1, 'a');
		}
	}
