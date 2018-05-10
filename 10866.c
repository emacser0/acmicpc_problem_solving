#include <stdio.h>
#include <string.h>
int deck[30000],fi=15001,bi=15000;
int n;
char buf[20];

void push_front();
void push_back();
void pop_front();
void pop_back();
void size();
void empty();
void front();
void back();
void doins(char[20]);

void (*fp[8])()={push_front,push_back,pop_front,pop_back,size,empty,front,back};
char ins[8][20]={"push_front","push_back","pop_front","pop_back","size","empty","front","back"};

int
main() {  
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%s",buf);
    doins(buf);
  }
}

void
push_front() {
    int n;
    scanf("%d",&n);
    fi--;
    deck[fi]=n;
}

void
push_back() {
    int n;
    scanf("%d",&n);
    bi++;
    deck[bi]=n;
}

void
pop_front() {
    if(bi-fi>-1) {
	printf("%d\n",deck[fi]);
	deck[fi]=0;
	fi++;
    }
    else {
	printf("%d\n",-1);
    }
}

void
pop_back() {
    if(bi-fi>-1) {
	printf("%d\n",deck[bi]);
	deck[bi]=0;
	bi--;
    }
    else {
	printf("%d\n",-1);
    }
}

void
size() {
    printf("%d\n",bi-fi+1);
}

void
empty() {
    printf("%d\n",bi-fi==-1?1:0);
}

void
front() {
    printf("%d\n",bi-fi>-1?deck[fi]:-1);
}

void
back() {
    printf("%d\n",bi-fi>-1?deck[bi]:-1);
}

void
doins(char str[20]) {
    for(int i=0;i<8;i++) {
	if(strcmp(ins[i],str)==0) {
	    fp[i]();
	}
    }
}
