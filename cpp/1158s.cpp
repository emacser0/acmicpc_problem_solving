#include <iostream>
#include <deque>
int n,k,i;std::deque<int> v;int main(){scanf("%d%d",&n,&k);for(i=1;i<=n;++i)v.push_back(i);putchar('<');for(i=(k-1)%n;;i=(i+k)%n){printf("%d%s",v.at(i),n-->1?", ":"");v.erase(v.begin()+i--);if(!n)break;}puts(">");}
