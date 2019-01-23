#include <cstdio>
#define d(n,e) if(r[n]){r[n]--;_d(x+1,r,s e a[x]);r[n]++;}
int i,n,a[104],o[4],t=-1e9,l=1e9;
void _d(int x,int r[4],int s){if(x==n)t=t>s?t:s,l=l<s?l:s;d(0,+);d(1,-);d(2,*);d(3,/);}
int main(){for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);for(i=0;i<4;i++)scanf("%d",o+i);_d(1,o,a[0]);printf("%d\n%d\n",t,l);}
