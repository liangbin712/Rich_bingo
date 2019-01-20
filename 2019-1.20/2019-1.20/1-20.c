1.#include<stdio.h>
#include<assert.h> 
#include<string.h>
//int Strcmp(const char * str1,const char * str2)
//{
//  assert(*str1);
//  assert(*str2);
//  for(int i = 0;str1[i] != '\0' && str2[i] != '\0';i++)
//  {
//    if(str1[i] > str2[i])
//    {
//      return 1; 
//    } 
//    if(str1[i] < str2[i])
//    {
//      return -1;
//    }
//  }
//  if(*str1 > *str2)
//  {
//    return 1;
//  }
//  if(*str2 > *str1)
//  {
//    return -1;
//  }
//  else{
//    return 0;
//  }
//}
2.  const char * Strstr(const char * str1, const char *  str2)
{
	const char *piont = NULL;
	const char *p = str1;
	const char *p1 = str2;
	const char *p2 = str2;
	int num = 0;
	assert(str1);
	assert(str2);
	if (strlen(str1) < strlen(str2))
	{
		return p;
	}
	while (*str1 != '\0')
	{
		if (*str1 == *str2)
		{
			p = str1;
			p++;
			(p1++);
			num++;
			if (*p1 != *p)
			{
				p1 == p2;
			}
		}
		str1++;
		str2++;
	}
	if (*str2 == '\0'&& num == strlen(str2))
	{
		return p2;
	}
	else{
		return piont;
	}
}
int main()
{
	char a[] = "ajkl";
	char b[] = "jkl";
	printf("%p\n", b);
	printf("%p", Strstr(a, b));
}