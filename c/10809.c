#include <stdio.h>
#include <string.h>
int location[26],l;
char word[100];

int
main() {  
  scanf("%s",word);
  for(int i=0;i<26;i++) {
    location[i]=-1;
  }
  l=strlen(word);
  for(int i=0;i<l;i++) {
    if(location[word[i]-97]==-1) {
      location[word[i]-97]=i;
    }
  }
  for(int i=0;i<26;i++) {
    printf("%d ",location[i]);
  }
  printf("\n");
}
