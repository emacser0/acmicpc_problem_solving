#include <cstdio>
int m,n,c[5],i,j,c_i,k;
char w[599][599];
int
main() {
  scanf("%d%d",&m,&n);
  for(i=0;i<5*m+1;i++)scanf("%s",w[i]);
  for(i=0;i<m;i++)
    for(j=0;j<n;j++) {
      c_i=0;
      for(k=0;k<4;k++)
        if(w[5*i+1+k][5*j+1]=='*')
          c_i++;
      c[c_i]++;
    }
  for(int i=0;i<5;i++)printf("%d ",c[i]);
  puts("");
}
