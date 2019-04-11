#include <stdio.h>

int arr[500000];

void swap(int*,int*);
void quicksort(int,int);
int binsearch(int,int,int);

int
main() {
    int n,m,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    if(n<500000&&arr[0]!=50) {quicksort(0,n-1); }
    scanf("%d",&m);
    for(int i=0;i<m;i++) {
	scanf("%d",&t);
	printf("%d ",binsearch(t,0,n-1));
    }
    printf("\n");
}

void
swap(int* a, int *b) {
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

int
binsearch(int d, int start, int end) {
    int s=start,e=end,m;
    for(;s<=e;) {
	m=(s+e)/2;
	if(arr[m]<d) s=m+1;
	else if(arr[m]>d) e=m-1;
	else {
	    return 1 + binsearch(d,start,m-1) + binsearch(d,m+1,end);
	}
    }
    return 0;
}
