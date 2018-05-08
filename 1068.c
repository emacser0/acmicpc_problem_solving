#include <stdio.h>
typedef struct node {
    int n;
    int left;
    int right;
} node;
node nodes[50];
void
visit(int n) {
    nodes[n].n=-1;
    nodes[n].left=-1;
    nodes[n].right=-1;
}
void
delete(int n) {
    if(nodes[n].left!=-1) {
	delete(nodes[n].left);
    }
    if(nodes[n].right!=-1) {
	delete(nodes[n].right);
    }
    visit(n);
}
int
main() {
    int n,t,sum=0;
    scanf("%d",&n);
    for(int i=0;i<50;i++) {
	nodes[i].n=-1;
	nodes[i].left=-1;
	nodes[i].right=-1;
    }
    for(int i=0;i<n;i++) {
	nodes[i].n=i;
	scanf("%d",&t);	
	if(t!=-1) {
	    if(nodes[t].left==-1) {
		nodes[t].left=i;
	    }
	    else {
		nodes[t].right=i;
	    }
	}
    }
    scanf("%d",&t);
    delete(t);
    for(int i=0;i<n;i++) {
	if(nodes[i].n!=-1&&nodes[i].left==-1&&nodes[i].right==-1) {
	    sum++;
	}
    }
    printf("%d\n",sum);
}
