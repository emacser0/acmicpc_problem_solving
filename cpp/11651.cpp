#include <cstdio>
#include <cstdlib>
int
compare(const void *a, const void *b) {
  int *ai=(int*)a;
  int *bi=(int*)b;
  if(ai[1]>bi[1]) {
    return 1;
  }
  else if(ai[1]<bi[1]) {
    return -1;
  }
  else if(ai[0]>bi[0]){
    return 1;
  }
  else if(ai[0]<bi[0]) {
    return -1;
  }
  else {
    return 0;
  }  
}
int n,p[100004][2];
int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d%d",p[i],p[i]+1);
  } 
  qsort(p,n,sizeof(int[2]),compare);  
  for(int i=0;i<n;i++) {
    printf("%d %d\n",p[i][0],p[i][1]);
  }
}
