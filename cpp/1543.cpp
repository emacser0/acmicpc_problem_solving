#include <cstdio>
#include <cstring>
char str[2504],word[50];
int main()
{
  fgets(str,2502,stdin);
  fgets(word,52,stdin);
  int slen=strlen(str),wlen=strlen(word),cnt=0;
  if(str[slen-1]=='\n')
  {
    str[slen-1]='\0',slen--;
  }
  if(word[wlen-1]=='\n')
  {
    word[wlen-1]='\0',wlen--;
  }
  for(int i=0;i<slen&&(slen-i+1>=wlen);i++)
  {
    if(!strncmp(str+i,word,wlen))
    {
      cnt++;
      i+=wlen-1;
    }
  }
  printf("%d\n",cnt);
}
