#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALLOCFORLINKEDLIST (linkednode *)malloc(sizeof(linkednode))

typedef struct node {
    char            ch;
    struct node    *next;
} linkednode;

linkednode     *lstacktop;
linkednode     *rstacktop;

void push_left(char);
void push_right(char);
char pop_left();
char pop_right();
void backspace();
void leftarrow();
void rightarrow();

char commandch[3]={ '-', '<', '>' };
void (*commandfp[3])()={backspace, leftarrow, rightarrow};
int
main() {
    int l,len;
    char buf[1000000];
    scanf("%d", &l);
    for (;l;l--) {
	scanf("%s",buf);
	len=strlen(buf);
	for(int i=0;i<len;i++) {
	    if (buf[i] == commandch[0]) {
		commandfp[0]();
	    }
            else if (buf[i] == commandch[1]) {
		commandfp[1]();
	    }
            else if (buf[i] == commandch[2]) {
		commandfp[2]();
	    }
            else {
		push_left(buf[i]);
	    }
	}
	for(;lstacktop!=NULL;) {
	    push_right(pop_left());
	}
	for(;rstacktop!=NULL;) {
	    printf("%c",pop_right());
	}
	printf("\n");
    }
}

void
push_left(char ch) {
    if (ch!='\0') {
	linkednode *t = ALLOCFORLINKEDLIST;
	t->ch=ch;
	t->next=lstacktop;
	lstacktop=t;
    }
}

void
push_right(char ch) {
    if (ch!='\0') {
	linkednode *t = ALLOCFORLINKEDLIST;
	t->ch = ch;
	t->next = rstacktop;
	rstacktop = t;
    }
}

char
pop_left() {
    char ch;
    linkednode *t;
    if (lstacktop!=NULL) {
	ch=lstacktop->ch;
	t=lstacktop->next;
	free(lstacktop);
	lstacktop = t;
	return ch;
    } else {
	return '\0';
    }
}

char
pop_right() {
    char ch;
    linkednode *t;
    if (rstacktop!=NULL) {
	ch=rstacktop->ch;
	t=rstacktop->next;
	free(rstacktop);
	rstacktop=t;
	return ch;
    }
    else {
	return '\0';
    }
}

void
backspace() {
    pop_left();
}

void
leftarrow() {
    push_right(pop_left());
}

void
rightarrow() {
    push_left(pop_right());
}
