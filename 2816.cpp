#include <cstdio>
#include <cstring>
int N,a,b,i,c;
char s[104];
int move(int x){for(i=0;i<x;i++)putchar(49);for(i=c;i<x;i++)putchar(52);}
int main(){for(scanf("%d",&N);scanf("%s",s),i<N;i++)a=strcmp(s,"KBS1")?a:i,b=strcmp(s,"KBS2")?b:i;move(a),c=1,move(b<a?b+1:b);}
