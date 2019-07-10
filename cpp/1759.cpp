#include <cstdio>
#include <cstdlib>
#include <cstring>
int l,c;
char letters[16];
void dfs(int x, char stack[16], int si)
{
  if(x>c)
  {
    return;
  }
  if(si==l)
  {
    int vowel_cnt=0,cons_cnt=0;
    for(int i=0;i<si;i++)
    {
      if(stack[i]=='a'||
      stack[i]=='e'||
      stack[i]=='i'||
      stack[i]=='o'||
      stack[i]=='u')
      vowel_cnt++;
      else cons_cnt++;
    }
    if(vowel_cnt>0&&cons_cnt>1)
    {
      stack[si]='\0';
      printf("%s\n",stack);
    }
    return;

  }
  stack[si++]=letters[x];
  dfs(x+1,stack,si);
  stack[--si]='\0';
  dfs(x+1,stack,si);
}
int cmp(const void *a,const void *b)
{
  int va=*(char*)a,vb=*(char*)b;
  if(va>vb) return 1;
  if(va==vb) return 0;
  else return -1;
}

int
main()
{
  scanf("%d%d",&l,&c);
  for(int i=0;i<c;i++)
  {
    scanf(" %c",letters+i);
  }
  qsort(letters,c/sizeof(char),sizeof(char),cmp);
  char stack[16]={0,};
  dfs(0,stack,0);
}
