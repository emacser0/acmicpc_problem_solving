#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define swap() {t=arr[x];arr[x]=arr[i];arr[i]=t;}
int n,arr[20],r[50000],ri,t;
char s[20];
int compare(const void *a,const void *b) {
  return *(int*)a>*(int*)b?1:*(int*)a==*(int*)b?0:-1;
}
void p(int x) {
  if(x==n){
    for(int i=n-1;i>=0;i--) {
      r[ri]+=arr[i]*round(pow(10,i));
    }
    ri++;
    return;
  }
  p(x+1);
  for(int i=x+1;i<n;i++) {
    swap()
    p(x+1);
    swap();
  }
}
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    arr[i]=i+1;
  }
  p(0);
  qsort(r,ri,sizeof(int),compare);
  for(int i=0;i<ri;i++) {
    sprintf(s,"%d",r[i]);
    for(int j=0;j<n;j++) {
      printf("%c ",s[j]);
    }
    puts("");
  }
}
