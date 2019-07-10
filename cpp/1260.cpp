#include <iostream>
#include <list>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;
typedef list<int> List;
typedef set<int> AdList;
typedef unordered_map<int,AdList> Graph;
int main()
{
  int n, m, v, v1, v2, curv;
  Graph graph;
  cin >> n >> m >> v;
  auto add_edge=[&graph](int v1,int v2)
  {
    Graph::iterator itr;
    if((itr=graph.find(v1))==graph.end())
    {
      graph.insert(pair<int,AdList>(v1,{v2}));
    }
    else
    {
      graph[v1].insert(v2);
    }
  };
  for(int i=0;i<m;i++)
  {
    cin >> v1 >> v2;
    add_edge(v1,v2);
    add_edge(v2,v1);
  }
  List buf,vtd;
  function<bool (int,int)> compare = [](int a,int b)->bool{return a>b;};
  function<void ()> start = [&]() {curv=buf.back(),buf.pop_back();};
  auto push_adv=[&]()
  {
    if(find(vtd.begin(),vtd.end(),curv)==vtd.end())
    {
      vtd.push_back(curv);
      List next;
      auto i=graph[curv];
      set_difference(i.begin(),i.end(),
      vtd.begin(),vtd.end(),
      back_inserter(next));
      next.sort(compare);
      for_each(next.begin(),next.end(),[&](int i) {
        buf.push_back(i);
      });
    }
  };
  auto printv=[&vtd]()
  {
    for(auto i:vtd){cout<<i<<" ";}cout<<"\n";
  };
  auto run=[&]()
  {
    buf.push_back(v);
    while(buf.size()>0)
    {
      start();
      push_adv();
    }
    printv();
    buf.clear();
    vtd.clear();
  };
  run();
  compare=[](int a,int b)->bool{return a<b;};
  start=[&](){curv=buf.front(),buf.pop_front();};
  run();
}
