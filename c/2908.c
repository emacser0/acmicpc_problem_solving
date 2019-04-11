#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a,b,l;
char bufa[100],bufb[100],tbuf[100];

int
main() {
    scanf("%s %s",bufa,bufb);
    l=strlen(bufa);
    for(int i=l-1;i>=0;i--) {
        tbuf[l-1-i]=bufa[i];
    }
    a=atoi(tbuf);
    l=strlen(bufb);
    for(int i=l-1;i>=0;i--) {
        tbuf[l-1-i]=bufb[i];
    }
    b=atoi(tbuf);
    printf("%d\n",a>b?a:b);
}
