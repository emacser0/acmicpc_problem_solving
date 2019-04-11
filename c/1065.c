#include <stdio.h>
#include <math.h>

int
getdigit(int n,int d) {
    return (n-n/(int)pow(10,d)*pow(10,d))/pow(10,d-1);
}

int
ishan(int n) {
    int t=n,c=1;
    int ps=-99,s=0;
    for(;t>=10;c++)
	t/=10;
    for(int i=1;i<c;i++) {
	s=getdigit(n,i)-getdigit(n,i+1);
	if(ps!=-99&&s!=ps) return 0;
	else ps=s;
    }
    return 1;
}

int
main() {
    int n,c=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
	if(ishan(i))
	    c++;
    }
    printf("%d\n",c);
}
