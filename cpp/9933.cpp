#include <cstdio>
#include <cstring>
void
strrev(char *str, size_t len, char *dest) {
  char new_str[len];
  for(int i=len-1;i>=0;i--) {
    new_str[len-i-1]=str[i];
  }
  for(int i=0;i<len;i++) {
    dest[i]=new_str[i];
  }
}
int
main() {
  int N,list_len=0;
  char str[20],passwd_list[101][20];
  scanf("%d",&N);
  for(int i=0;i<N;i++) {
    scanf("%s",str);
    strrev(str,strlen(str),passwd_list[list_len++]);
    for(int i=0;i<list_len;i++) {
      if(strcmp(passwd_list[i],str)==0) {
        printf("%ld %c\n",strlen(str),str[strlen(str)/2]);
        return 0;
      }
    }
  }
  for(int i=0;i<list_len;i++) {
    printf("%s\n",passwd_list[i]);
  }
}
