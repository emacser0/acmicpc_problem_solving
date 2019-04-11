#include <iostream>
#include <vector>
#include <array>
using std::cin;
using std::cout;
using std::vector;
using std::array;
int t,xlen,ylen,k;
array<array<int,199>,199> map,visited;
int table[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
vector<array<int,2>> entrypoint;
int
pcheck(int p, int len) {
    return p>=0 and p<len;
}

int
mapcheck(int x, int y) {
    return map[y][x] and !visited[y][x];
}

int
check(int x, int y) {
    return pcheck(x,xlen) and pcheck(y,ylen) and mapcheck(x,y);
}

void
dfs(int x, int y) {
    int nx,ny;
    visited[y][x]=1;
    for(int i=0;i<4;i++) {
        nx=x+table[i][0],ny=y+table[i][1];
        if(check(nx,ny)) {
            dfs(nx,ny);
        }
    }
}

int
main() {
    int x,y,cnt=0;
    cin >> t;
    for(int i=0;i<t;i++) {
        cin >> xlen>> ylen >> k;
        for(int j=0;j<k;j++) {
            cin >> x >> y;
            map[y][x]=1;
            entrypoint.push_back({x,y});
        }
        for(auto i : entrypoint) {
            if(check(i[0],i[1])) {
                dfs(i[0],i[1]);
                cnt++;
            }
        }
        map={{0},};
        visited={{0},};
        cout << cnt << "\n";
        cnt=0;
    }
}
