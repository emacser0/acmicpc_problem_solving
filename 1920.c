#include <stdio.h>
int arr[200000];
void swap(int*,int*);
int bsearch(int,int,int);
void qsort(int,int);
int main() {
    int n,m,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
	scanf("%d",&arr[i]);
    }
    qsort(0,n-1);
    scanf("%d",&m);
    for(int i=0;i<m;i++) {
    	scanf("%d",&t);
    	printf("%d\n",bsearch(t,0,n-1));
    }
}
void
swap(int *a, int *b) {
    int t=*a;
    *a=*b,*b=t;
}
void
qsort(int start, int end) {
    int stack[(end-start)/2+1][2],ei=-1;
    int s,e,i,j;
    stack[++ei][0]=start,stack[ei][1]=end;
    for(;ei>-1;) {
	s=stack[ei][0],e=stack[ei--][1];
	i=s,j=e;
	if(e-s<=1) {
	    if(arr[s]>arr[e]) swap(&arr[s],&arr[e]);
	    continue;
	}
	for(;i<j;) 
	    if(arr[i]>=arr[e]) 
		if(arr[j]<arr[e]) swap(&arr[i++],&arr[j]);
		else j--;
	    else i++;
	swap(&arr[i],&arr[e]);
	if(s<i) stack[++ei][0]=s,stack[ei][1]=i-1;
	if(e>i) stack[++ei][0]=i+1,stack[ei][1]=e;
    }
}
int
bsearch(int d, int s, int e) {
    int i=s,j=e,m;
    for(;i<=j;) {
	m=(i+j)/2;
	if(arr[m]==d) return 1;
	else if(arr[m]<d) i=m+1;
	else j=m-1;
    }
    return 0;	
}
