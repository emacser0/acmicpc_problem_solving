#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[800],*c;
int T,S;
int main()
{
  scanf("%d\n",&T);
  for(int i=0;i<T;i++,S=0)
  {
    fgets(s,800,stdin);
    S+=atoi(strtok(s," "));
    while((c=strtok(NULL," ")))
    {
      S+=atoi(c);
    }
    printf("%d\n",S);
  }
}
