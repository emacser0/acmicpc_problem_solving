#include <stdio.h>
typedef struct node {
    char ch;
    char left;
    char right;
} node;
node nodes[26];
int
hash(char ch) {
    return ch-'A';
}
void
visit(char ch){
    printf("%c",ch);
}
void
preorder(char ch) {
    visit(ch);
    if(nodes[hash(ch)].left>='A'&&nodes[hash(ch)].left<='Z') {
	preorder(nodes[hash(ch)].left);
    }
    if(nodes[hash(ch)].right>='A'&&nodes[hash(ch)].right<='Z') {
	preorder(nodes[hash(ch)].right);
    }
}
void
inorder(char ch) {
    if(nodes[hash(ch)].left!='.') {
	inorder(nodes[hash(ch)].left);
    }
    visit(ch);
    if(nodes[hash(ch)].right!='.') {
	inorder(nodes[hash(ch)].right);
    }
    
}
void
postorder(char ch) {
    if(nodes[hash(ch)].left!='.') {
	postorder(nodes[hash(ch)].left);
    }
    if(nodes[hash(ch)].right!='.') {
	postorder(nodes[hash(ch)].right);
    }
    visit(ch);
}
int main() {
    int n;
    char buf[3][5];
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
	for(int i=0;i<3;i++) {
	    scanf("%s",buf[i]);
	}
	nodes[hash(buf[0][0])].ch=buf[0][0];
	nodes[hash(buf[0][0])].left=buf[1][0];
	nodes[hash(buf[0][0])].right=buf[2][0];	
    }
    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');
    printf("\n");
}
