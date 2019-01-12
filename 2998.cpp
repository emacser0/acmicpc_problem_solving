#include <cstdio>
#include <cstring>
char bin[101],oct[101];
int oct_i;
int
main() {
  scanf("%s",bin);
  int len = strlen(bin);
  for(int i=len-1;i>=0;i-=3) {
    int converted=0;
    if(i==0) {
      converted += bin[i]-'0';
    }
    else if(i==1) {
      converted += 0x2*(bin[i-1]-'0')+0x1*(bin[i]-'0');
    }
    else {
      converted += 0x4*(bin[i-2]-'0')+0x2*(bin[i-1]-'0')+0x1*(bin[i]-'0');
    }
    oct[oct_i++]=converted;
  }
  for(int i=oct_i-1;i>=0;i--) {
    printf("%d",oct[i]);
  }
  puts("");
}
