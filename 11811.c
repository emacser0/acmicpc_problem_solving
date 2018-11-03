#include <stdio.h>
int n,a[1001][1001],a_result[1001];
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      scanf("%d",&a[i][j]);
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      a_result[i]|=a[i][j];
      a_result[j]|=a[i][j];
    }
  }
  for(int i=0;i<n;i++) {
    printf("%d ",a_result[i]);
  }
  printf("\n");
}
