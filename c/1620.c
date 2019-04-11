#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p{
    int no;
    char s[25];
}p;

p pbs[100001];
p pbno[100001];
int stack[10000][2],ei=-1;

void swap(p*,p*);
void quicksort(int,int);
void binsearch(int,int,char[25]);

int main() {
    int n,m,nbuf;
    char buf[25];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
	scanf("%s",buf);
	strcpy(pbs[i].s,buf);
	strcpy(pbno[i].s,buf);
	pbs[i].no=i;
	pbno[i].no=i;
    }
    quicksort(0, n-1);
    for(int i=0;i<m;i++) {
    	scanf("%s",buf);
    	if(buf[0]>='0'&&buf[0]<='9') {
    	    nbuf=atoi(buf);
	    printf("%s\n",pbno[nbuf-1].s);
    	}
    	else binsearch(0,n-1,buf);
    }
}

void swap(p *a,p *b) {
    p t;
    strcpy(t.s,a->s);
    strcpy(a->s,b->s);
    strcpy(b->s,t.s);
    t.no=a->no;
    a->no=b->no;
    b->no=t.no;
}
void
quicksort(int start, int end) {
    int s,e,i,j,p;
    stack[++ei][0]=start,stack[ei][1]=end;
    for(;ei>-1;)  {
	s=stack[ei][0],e=stack[ei--][1];
	i=s,j=e,p=e;
	if(e-s==1){
	    if(strcmp(pbs[s].s,pbs[e].s)>0) swap(&pbs[s],&pbs[e]);
	    continue;
	}
	else if(e-s==0) continue;
	for(;i<j;)
	    if(strcmp(pbs[i].s,pbs[p].s)>=0)
		if(strcmp(pbs[j].s,pbs[p].s)<0) swap(&pbs[i++],&pbs[j]);
		else j--;
	    else i++;
	swap(&pbs[i],&pbs[p]);
	if(s<j) stack[++ei][0]=s,stack[ei][1]=i-1;
	if(e>i) stack[++ei][0]=i+1,stack[ei][1]=e;
    }
}
void
binsearch(int s, int e, char str[25]) {
    int i=s,j=e,m=(i+j)/2,r=strcmp(pbs[m].s,str);
    for(;i<=j;) {
	m=(i+j)/2;
	r=strcmp(pbs[m].s,str);
	if(r==0) {
	    printf("%d\n",pbs[m].no+1);
	    return;
	} 
	else if(r<0) i=m+1;
	else j=m-1;
    }    
}
