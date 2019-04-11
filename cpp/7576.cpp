#include <iostream>
#include <deque>
#include <vector>
#include <array>
using std::cin;
using std::cout;
using std::deque;
using std::vector;
using std::array;
int xlen,ylen,map[2000][2000],visited[2000][2000];
vector<array<int,2>> donelist;
int
pcheck(int p, int len) {
    return p>=0 and p<len;
}

int
mapcheck(int x, int y) {
    return !map[y][x] and !visited[y][x];
}

int
check(int x, int y) {
    return pcheck(x,xlen) and pcheck(y,ylen) and mapcheck(x,y);
}

int tomatocheck() {
    for(int i=0;i<ylen;i++) {
        for(int j=0;j<xlen;j++) {
            if(!map[i][j]) {
                return -1;
            }
        }
    }
    return 0;
}
int table[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
int
bfs() {
    deque<array<int,3>> queue;
    array<int,3> t;
    int nx,ny;
    int day=0;
    for(auto i : donelist) {
        queue.push_back({i[0],i[1],0});
    }
    while(queue.size()) {
        t=queue.front();
        for(auto i : table) {
            nx=t[0]+i[0],ny=t[1]+i[1];
            if(check(nx,ny)) {
                map[ny][nx]=1;
                visited[ny][nx]=1;
                queue.push_back({nx,ny,t[2]+1});
                day=t[2]+1;
            }
        }
        queue.pop_front();
    }
    return day;
}
int
main() {
    cin >> xlen >> ylen;
    for(int i=0;i<ylen;i++) {
        for(int j=0;j<xlen;j++) {
            cin >> map[i][j];
            if(map[i][j]==1) {
                visited[i][j]=1;
                donelist.push_back({j,i});
            }
        }
    }
    if(tomatocheck()==0) {
        cout << 0;
        return 0;
    }
    int day=bfs();
    if(tomatocheck()==-1) {
        cout << -1;
        return 0;
    }
    cout << day << "\n";
}
