#include <cstdio>
int cnt[5];
char buf[14];
int main()
{
  scanf("%s",buf);
  for(int i=0;buf[i]!='\0';i++)
    if(buf[i]=='2') cnt[0]++;
    else if(buf[i]=='0') cnt[1]++;
    else if(buf[i]=='1') cnt[2]++;
    else if(buf[i]=='8') cnt[3]++;
    else cnt[4]++;
  if(!cnt[4])
    if(cnt[0]&&cnt[1]&&cnt[2]&&cnt[3])
      if(cnt[0]==cnt[1]&&cnt[1]==cnt[2]&&cnt[2]==cnt[3])
        printf("8\n");
      else printf("2\n");
    else printf("1\n");
  else printf("0\n");
}
