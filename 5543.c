#include <stdio.h>
int ns[5];
int hm,dm;
int main() {
    for(int i=0;i<5;i++) {
        scanf("%d",&ns[i]);
    }
    hm=ns[0]<ns[1]?ns[0]<ns[2]?ns[0]:ns[2]:ns[1]<ns[2]?ns[1]:ns[2];
    dm=ns[3]<ns[4]?ns[3]:ns[4];
    printf("%d\n",hm+dm-50);
}
