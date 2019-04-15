#include <stdio.h>
long long l[5],min=2e9,c;
int
main() {
  for(int i=0;i<5;i++) {
    scanf("%d",l+i);
    min=min<l[i]?min:l[i];
  }
  for(int i=min;i<2e9;i++,c=0) {
    for(int j=0;j<5;j++) {
      if(i%l[j]==0){c++;}
    }
    if(c>2){printf("%d\n",i);break;}
  }
}
