#include<stdio.h>    
#include<assert.h>    
#include<string.h>    
char * Strncat ( char * destination, const char * source, size_t num )    
{    
  assert(destination != NULL );
  assert(source != NULL);
  size_t i = 0;    
  while(*destination != '\0')
  {
    ++destination;
  }
  while(i < num)    
  {    
    *(destination++) = source[i];
    i++;
  }    
  *(destination) = '\0';
  printf("%s\n",destination);

  return destination;    
}
char *Strncpy(char *destination,const char *source,size_t num)
{
  size_t i = 0; 
  while(i < num)
  {
    *destination = *source;
    destination++;
    source++;
  }
  return destination;
}
int main ()
{
    char str1[]= "To be or not to be";
      char str2[40];
        char str3[40];
          /* copy to sized buffer (overflow safe): */
          strncpy ( str2, str1, sizeof(str2)  );
            /* partial copy (only 5 chars): */
            strncpy ( str3, str2, 5  );
              str3[5] = '\0';   /* null character manually added */
                puts (str1);
                  puts (str2);
                    puts (str3);
                      return 0;
}
//int main ()    
//{   
//   char str1[20] = "To be ";    
//   char str2[20] = "or not to be ";    
//   Strncat (str1, str2, 6);                                                                                                                                                     
//   printf("%s",str1);    
//}    

