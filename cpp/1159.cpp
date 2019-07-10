#include <cstdio>
int n,cnt[26],cond;
char buf[154][34];
int
main()
{
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%s",buf[i]);
    cnt[buf[i][0]-'a']++;
  }
  for(int i=0;i<26;i++) if(cnt[i]>4) cond=1;
  if(!cond)
  {
    printf("PREDAJA\n");
    return 0;
  }
  for(int i=0;i<26;i++)
  if(cnt[i]>4) putchar('a'+i);
  puts("");
}
