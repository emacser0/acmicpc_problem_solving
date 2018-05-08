#include <stdio.h>
#include <string.h>
int main() {
    int t,r,l;
    char buf[30];
    scanf("%d",&t);
    for(int i=0;i<t;i++) {
        scanf("%d",&r);
        scanf("%s",buf);
        l=strlen(buf);
        for(int j=0;j<l;j++) {
            for(int k=0;k<r;k++) {
                putchar(buf[j]);
            }
        }
	putchar('\n');
    }
}
