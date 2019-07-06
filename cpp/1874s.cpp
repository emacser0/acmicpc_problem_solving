#include <iostream>
int n,q,c=1,s[7<<14],si,r[7<<15],ri,i;
void push(int n){s[si++]=n,ri++;}
void pop(){si--,r[ri++]=1;}
int main(){std::cin>>n;for(i=0;i<n;++i){std::cin>>q;while(c<=q)push(c++);if(s[si-1]!=q)break;pop();}if(ri==n*2)for(i=0;i<ri;++i)std::cout<<(r[i]?'-':'+')<<"\n";else std::cout<<"NO\n";}
