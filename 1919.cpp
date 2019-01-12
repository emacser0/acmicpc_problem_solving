#include <cstdio>
char a[1001],b[1001];
int a_count[26],b_count[26];
int
abs_sub(int a, int b) {
  return a>b?(a-b):(b-a);
}
int
main() {
  scanf("%s%s",a,b);
  for(int i=0;a[i]!='\0';i++) {
    a_count[a[i]-'a']++;
  }
  for(int i=0;b[i]!='\0';i++) {
    b_count[b[i]-'a']++;
  }
  int count=0;
  for(int i=0;i<26;i++) {
    count += abs_sub(a_count[i],b_count[i]);
  }
  printf("%d\n",count);
}
