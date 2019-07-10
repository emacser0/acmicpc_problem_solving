#include <cstdio>
#include <vector>
#include <array>
using std::vector;
using std::array;
vector<array<int,3>> people;
int
cmp(array<int,3> a,array<int,3> b)
{
  return a[0]>b[0] and a[1]>b[1]?1:a[0]<b[0] and a[1]<b[1]?-1:0;
}
void
go(int i, vector<int> v)
{
  if(i<people.size())
  {
    go(i+1,v);
    v.push_back(i);
    if(v.size()<2)
    {
      go(i+1,v);
    }
    else
    {
      int ret=cmp(people[v[0]],people[v[1]]);
      if(ret==1)
      {
        people[v[1]][2]++;
      }
      else if(ret==-1)
      {
        people[v[0]][2]++;
      }
    }
  }
}
int n,a,b;
int
main()
{
  for(scanf("%d",&n);n>0;n--)
  {
    scanf("%d%d",&a,&b);
    people.push_back({a,b,1});
  }
  go(0,{});
  for(int i=0;i<people.size();i++)
  {
    printf("%d ",people[i][2]);
  }
}
