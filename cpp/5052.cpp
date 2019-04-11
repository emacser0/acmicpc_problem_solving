#include <iostream>
#include <string>
#include <set>
#define c std::cin>>
int t,n,r;
int main(){
  std::string a;
  std::set<std::string> ss,us;
  c t;
  for(int i=0;i<t;i++){
    c n;
    us={},ss={},r=1;
    for(int j=0;j<n;j++)
      c a,ss.insert(a);
    for(auto i : ss){
      for(int j=0;j<i.size();j++)
        if(us.find(i.substr(0,j))!=us.end())
          r=0;
      us.insert(i);
    }
    printf("%s\n",r?"YES":"NO");
  }
}
