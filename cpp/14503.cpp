#include <iostream>
#include <vector>
#include <array>
using std::cin;
using std::cout;
using std::vector;
using std::array;
int xlen,ylen,cnt=1;
int robot[3];
array<array<int,51>,51> room;
array<array<int,51>,51> visited;
int table[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
inline int
wallcheck(int r, int c) {
    return !room[r][c];
}
inline int
visitedcheck(int r, int c) {
    return !visited[r][c];
}
inline int
check(int r, int c) {
    return wallcheck(r,c) and visitedcheck(r,c);
}
void
go(int r, int c, int d) {
    int nr,nc,nd=d;
    for(int i=0;i<4;i++) {
        nd=(nd+3)%4;
        nr=r+table[nd][1],nc=c+table[nd][0];
        if(check(nr,nc)) {
            visited[nr][nc]=1;
            cnt++;
            go(nr,nc,nd);
            return;
        }
    }
    nd=(d+2)%4;
    nr=r+table[nd][1],nc=c+table[nd][0];
    if(wallcheck(nr,nc)) {
        go(nr,nc,d);
    }
}
int
main() {
    cin >> ylen >> xlen;
    for(int i=0;i<3;i++) {
        cin >> robot[i];
    }
    for(int i=0;i<ylen;i++) {
        for(int j=0;j<xlen;j++) {
            cin >> room[i][j];
        }
    }
    visited[robot[0]][robot[1]]=1;
    go(robot[0],robot[1],robot[2]);
    cout << cnt << "\n";
}
