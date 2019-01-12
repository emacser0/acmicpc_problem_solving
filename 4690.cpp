#include <cstdio>
#include <cmath>
int p[101];
int
main() {
  for(int i=1;i<=100;i++)p[i]=pow(i,3);
  for(int a=2;a<=100;a++)
    for(int b=2;b<=a;b++)
      for(int c=b;c<=a;c++)
        for(int d=c;d<=a;d++)
          if(p[a]==p[b]+p[c]+p[d])
            printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
}
