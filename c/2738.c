#include <stdio.h>
int n,m,matrix[104][104],c;
int
main() {
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      scanf("%d",&matrix[i][j]);
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      scanf("%d",&c);
      printf("%d ",matrix[i][j]+c);
    }
    puts("");
  }
}
