#include <iostream>
#include <vector>
using vint = std::vector<int>;
using vint2d = std::vector<std::vector<int>>;
int
main() {
  int n,m,r,c,d;
  int buf;
  int fd;
  int cnt=0;
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> m >> r >> c >> d;  
  vint2d room(n);  
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {      
      std::cin >> buf;
      room[i].push_back(buf);
    }
  }
  auto clean=[&](int x, int y){
    if(room[y][x]!=-1) {
      room[y][x]=-1;
      cnt++;
    }    
  };
  auto cdirl=[&d](){
    d=(d-1)%4;
    if(d<0) {
      d=3;
    }
  };  
  while(1) {
    clean(r,c);
    fd=d;
    do {
      if(d==0) {
        if(r-1>=0&&!room[c][r-1]) {
          r-=1;
          cdirl();
          continue;
        }
        cdirl();
      }
      if(d==1) {
        if(c-1>=0&&!room[c-1][r]) {
          c-=1;
          cdirl();
          continue;
        }
        cdirl();
      }
      if(d==2) {
        if(r+1<m&&!room[c][r+1]) {
          r+=1;
          cdirl();
          continue;
        }
        cdirl();
      }
      if(d==3) {
        if(c+1<n&&!room[c+1][r]) {
          c+=1;
          cdirl();
          continue;
        }
        cdirl();
      }
    } while(d!=fd);
    if(d==0) {
      if(c+1==n||room[c+1][r]==1) {
        break;
      }
      c+=1;
    }
    if(d==1) {
      if(r-1<0||room[c][r-1]==1) {
        break;
      }
      r-=1;
    }
    if(d==2) {
      if(c-1<0||room[c-1][r]==1) {
        break;
      }
      c-=1;
    }
    if(d==3) {
      if(r+1==m||room[c][r+1]==1) {
        break;
      }
      r+=1;
    }
  }
  std::cout << cnt << "\n";
}
