#include <stdio.h>
#include <string.h>
int c[26];
int m,mc;
int main()
{
    char buf[1000001];
    int len;
    gets(buf);
    len=strlen(buf);
    for(int i=0;i<len;i++) {
        c[buf[i]-(buf[i]>'Z'?'a':'A')]++;
     }
     for(int i=0;i<26;i++) {
         if(c[m]==c[i]) {
             mc++;
         }
         else if(c[m]<c[i]) {
             m=i;
             mc=1;
         }
    }
    printf("%c\n",mc==1?(m+'A'):'?');
}
