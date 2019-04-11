#include <stdio.h>
#include <string.h>
#define QUEUE_SIZE 10000
int queue[QUEUE_SIZE],bkupqueue[QUEUE_SIZE],fi,bi=-1;
int n;
char buf[10];

void push();
void pop();
void size();
void empty();
void front();
void back();
void doins(char[10]);

char ins[6][10]={"push","pop","size","empty","front","back"};
void (*fp[6])()={push,pop,size,empty,front,back};

int
main() {
  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%s",buf);
    doins(buf);
  }
}

void
push() {
    int n;
    scanf("%d",&n);
    bi++;
    queue[bi]=n;
    if(fi>QUEUE_SIZE/2) {
	for(int i=fi;i<=bi;i++) {
	    bkupqueue[i-fi]=queue[i];
	}
	for(int i=0;i<bi-fi+1;i++) {
	    queue[i]=bkupqueue[i];
	}
	bi=bi-fi;
	fi=0;
    }
}

void
pop() {
    if(fi<=bi) {
	printf("%d\n",queue[fi]);
	queue[fi]=0;
	fi++;
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
    int ret=fi>bi?1:0;
    printf("%d\n",ret);
}

void
front() {
    if(bi-fi==-1) {
	printf("%d\n",-1);
    }
    else {
	printf("%d\n",queue[fi]);
    }
}

void
back() {
    if(bi-fi==-1) {
	printf("%d\n",-1);
    }
    else {
	printf("%d\n",queue[bi]);	
    }
}

void
doins(char str[10]) {
    for(int i=0;i<6;i++) {
	if(strcmp(str,ins[i])==0) {
	    fp[i]();
	    break;
	}
    }
}
