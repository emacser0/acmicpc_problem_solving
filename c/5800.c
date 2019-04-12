#include <stdio.h>
int T,t,n,arr[104],sum,gm;
void insert(int x) {
  for(int i=x-1;i>=0;i--) {
    if(arr[i]>arr[i+1]) {
      t=arr[i];arr[i]=arr[i+1];arr[i+1]=t;
    }
    else break;
  }
}
int
main() {
  scanf("%d",&T);
  for(int i=0;i<T;i++) {
    scanf("%d",&n);
    sum=0;gm=0;
    for(int j=0;j<n;j++) {
      scanf("%d",arr+j);
      sum+=arr[j];
      insert(j);
    }
    for(int j=0;j<n-1;j++) gm=(arr[j+1]-arr[j])>gm?arr[j+1]-arr[j]:gm;
    printf("Class %d\nMax %d, Min %d, Largest gap %d\n",i+1,arr[n-1],arr[0],gm);
  }
}
