N,cnt[26],max,i;
char s[1004],maxc;
main()
{
  scanf("%d%s",&N,s);
  for(;N;cnt[s[--N]-97]++);
  for(;i<26;++i)if(cnt[i]>max)max=cnt[i],maxc=97+i;
  printf("%c %d\n",maxc,max);
}
