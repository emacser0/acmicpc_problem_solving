#include <stdio.h>

int n,arr[1000];

void swap(int*,int*);
void quicksort(int,int);

int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&arr[i]);
  }
  quicksort(0,n-1);
  for(int i=0;i<n;i++) {
    printf("%d\n",arr[i]);
  }
}

void
swap(int* a,int *b) {
  int t=*a;
  *a=*b,*b=t;
}

void
quicksort(int start, int end) {
  int stack[(end-start)/2][2],ei=-1;
  int s,e,i,j;
  stack[++ei][0]=start,stack[ei][1]=end;
  for(;ei>-1;) {
    s=stack[ei][0],e=stack[ei--][1];
    i=s,j=e;
    if(e-s<=1) {
      if(arr[s]>arr[e]) {
        swap(&arr[s],&arr[e]);        
      }
      continue;
    }
    for(;i!=j;) {
      if(arr[i]>=arr[e]) {
        if(arr[j]<arr[e]) {
          swap(&arr[i++],&arr[j]);
        }
        else {
          j--;
        }
      }
      else {
        i++;
      }
    }
    swap(&arr[i],&arr[e]);
    if(i-s>1) {
      stack[++ei][0]=s,stack[ei][1]=i-1;
    }
    if(e-i>1) {
      stack[++ei][0]=i+1,stack[ei][1]=e;
    }
  }
}
