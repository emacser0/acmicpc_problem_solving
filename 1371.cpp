#include <cstdio>
char str[5001];
int count[26],max,max_i;
int
main() {
  char ch;
  while((ch=getchar())!=EOF) {
    if(ch>='a'&&ch<='z') {
      count[ch-'a']++;
    }
  }
  for(int i=0;i<26;i++) {
    if(max<count[i]) {
      max=count[i];
      max_i=i;
    }
  }
  for(int i=max_i;i<26;i++) {
    if(count[i]==max) {
      printf("%c",i+'a');
    }
  }
  puts("");
}
