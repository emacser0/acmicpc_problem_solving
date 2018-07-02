int arr[100000];

void
swap(int *a, int *b) {
  int t=*a;
  *a=*b;
  *b=t;
}

void
qsort(int s, int e) {
    int i=s,j=e,p=e;
    if(e-s==1) {
	if(arr[s]>arr[e]) {
	    swap(&arr[s],&arr[e]);
	}
	return;
    }
    else if(e-s==0) return;
    for(;i<j;) {
	if(arr[i]>=arr[p]) {
	    if(arr[j]<arr[p]) {
		swap(&arr[i],&arr[j]);
		i++;
	    }
	    else j--;
	}
	else i++;
    }
    swap(&arr[i],&arr[p]);
    if(s<i) qsort(s,i-1);
    if(e>i) qsort(i+1,e);
}
