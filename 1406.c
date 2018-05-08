#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALLOCFORLINKEDLIST (linkednode*)malloc(sizeof(linkednode))
#define NUMBEROFCOMMAND 4

typedef struct node {
    char ch;
    struct node *prev;
} linkednode;
linkednode *lstacktop;
linkednode *rstacktop;

void push_left(char);
void push_right(char);
char pop_left();
char pop_right();
void free_leftstack();
void free_rightstack();
void L();
void D();
void B();
void P();
void getcommand(char);
char commandch[NUMBEROFCOMMAND]={'L','D','B','P'};
void (*commandfp[NUMBEROFCOMMAND])()={L,D,B,P};

int
main() {
    char text[100000];
    int n;
    int len;
    char buf[5];
    scanf("%s",text);
    scanf("%d",&n);
    len=strlen(text);
    for(int i=0;i<len;i++) {
	push_left(text[i]);
    }
    for(int i=0;i<n;i++) {
    	scanf("%s",buf);
    	getcommand(buf[0]);
    }
    for(;lstacktop!=NULL;) {
    	push_right(pop_left());
    }
    for(;rstacktop!=NULL;) {
    	printf("%c",pop_right());
    }
    printf("\n");
    free_leftstack();
    free_rightstack();
}

void
push_left(char ch) {
    linkednode *t;
    t=ALLOCFORLINKEDLIST;
    t->ch=ch;
    t->prev=lstacktop;
    lstacktop=t;
}

void
push_right(char ch) {
    linkednode *t;
    t=ALLOCFORLINKEDLIST;
    t->ch=ch;
    t->prev=rstacktop;
    rstacktop=t;
}

char
pop_left() {
    char ch;
    linkednode *t;
    if(lstacktop!=NULL) {
	ch=lstacktop->ch;
	t=lstacktop->prev;
	free(lstacktop);
	lstacktop=t;
	return ch;
    }
    else {
	return '\0';
    }
}

char
pop_right() {
    char ch;
    linkednode *t;
    if(rstacktop!=NULL) {
	ch=rstacktop->ch;
	t=rstacktop->prev;
	free(rstacktop);
	rstacktop=t;
	return ch;
    }
    else {
	return '\0';
    }
}

void
free_leftstack() {
    linkednode *t;
    for(;lstacktop!=NULL;) {
	t=lstacktop->prev;
	free(lstacktop);
	lstacktop=t;
    }
}

void
free_rightstack() {
    linkednode *t;
    for(;rstacktop!=NULL;) {
	t=rstacktop->prev;
	free(rstacktop);
	rstacktop=t;
    }
}

void
L() {
    if(lstacktop!=NULL) {
	push_right(pop_left());
    }
}

void
D() {
    if(rstacktop!=NULL) {
	push_left(pop_right());
    }
}

void
B() {
    if(lstacktop!=NULL) {
	pop_left();
    }
}

void
P() {
    char buf[5];
    scanf("%s",buf);
    push_left(buf[0]);
}

void
getcommand(char ch) {
    for(int i=0;i<NUMBEROFCOMMAND;i++) {
	if(ch==commandch[i]) {
	    commandfp[i]();
	}
    }
}
