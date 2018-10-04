#include <iostream>
#include <array>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::array;
using std::vector;
using std::pow;
using std::sqrt;
vector<array<int,3>> campentry;
int parent[3001];
int check[3001];
int t,n;
void
init() {
  for(int i=0;i<3001;i++) {
    parent[i]=i;
    check[i]=0;
  }
  campentry={};
}
int
is_group(array<int,3> a, array<int,3> b) {
  return pow(b[0]-a[0],2)+pow(b[1]-a[1],2) <= \
    pow(a[2]+b[2],2);
}
int
Find(int x) {
  if(x==parent[x]) {
    return x;
  }
  return parent[x]=Find(parent[x]);
}
void
Union(int x, int y) {
  x=Find(x);
  y=Find(y);
  if(x==y) {
    return;
  }
  if(x != y) {
    parent[x]=y;
  }
}
int
main() {
  int x,y,r;
  for(cin >> t;t>0;t--) {
    cin >> n;
    init();
    for(int i=0;i<n;i++) {
      cin >> x >> y >> r;
      campentry.push_back({x,y,r});
    }
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        if(is_group(campentry[i],campentry[j]) && \
           Find(i)!=Find(j)) {
          Union(i,j);
        }
      }
    }
    int cnt=0;
    for(int i=0;i<n;i++) {
      int p=Find(i);
      if(!check[p]) {
        check[p]=1;
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
}
