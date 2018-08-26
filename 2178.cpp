#include <iostream>
#include <string>
#include <deque>
#include <array>
using std::cin;
using std::cout;
using std::string;
using std::deque;
using std::array;
int map[200][200];
int visited[200][200];
int xlen,ylen,depth;
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
int table[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
void bfs() {
    array<int,3> t;
    int nx,ny;
    deque<array<int,3>> queue;
    queue.push_back({0,0,1});
    visited[0][0]=1;
    for(;queue.size()>0;) {
        for(int i=0;i<4;i++) {
            t=queue.front();
            nx=t[0]+table[i][0],ny=t[1]+table[i][1];
            if(check(nx,ny)) {
                visited[ny][nx]=1;
                t[2]++;
                if(nx==xlen-1 and ny==ylen-1) {
                    depth=t[2];
                    return;
                }
                queue.push_back({nx,ny,t[2]});
            }
        }
        queue.pop_front();
    }
}
int
main() {
    string buf;
    cin >> ylen >> xlen;
    for(int i=0;i<ylen;i++) {
        cin >> buf;
        for(int j=0;j<buf.size();j++) {
            map[i][j]=buf[j]-'0';
        }
    }
    bfs();
    cout << depth << "\n";
}
