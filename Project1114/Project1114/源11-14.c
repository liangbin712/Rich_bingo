#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main()
{
	void *p = 12345;
	char * q = (char *)p;
	for (int i = 0; i < 5;i++)
	{
		printf("%c", p);
		q++;
	}
	system("pause");
}
