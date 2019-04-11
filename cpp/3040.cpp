#include <iostream>
int n[9],m[9][9],sum;
int
main() {
  for(int i=0;i<9;i++) {
    scanf("%d",&n[i]);
    sum += n[i];
  }
  for(int i=0;i<9;i++) {
    for(int j=0;j<9;j++) {
      if(sum - n[i] - n[j] == 100) {
        for(int k=0;k<9;k++) {
          if(k!=i && k!=j) {
            printf("%d\n",n[k]);
          }
        }
        return 0;
      }
    }
  }
}
