#include <cstdio>
int x=0,lvl=1;
int
main() {
	scanf("%d", &x);
	int i = 1,cnt=0;
	for (; i < x; lvl++, i += lvl);
	i -= lvl; 
	for (; i < x; i++, cnt++);
	if (lvl % 2) {
		printf("%d/%d\n",lvl-cnt+1,cnt);
	}
	else {
		printf("%d/%d\n",cnt,lvl-cnt+1);
	}
} 