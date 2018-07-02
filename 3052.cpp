#include <cstdio>
#include <set>
#include <functional>
using namespace std;
int
main() {
  int buf;
  set<int> rems;
  function<void (int)> loop=[&](int n){
    if(n<10) {
      scanf("%d",&buf);
      rems.insert(buf%42);
      loop(n+1);
    }  
  };
  loop(0);
  printf("%ld\n",rems.size());
}
