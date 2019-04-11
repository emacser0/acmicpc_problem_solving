#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::array;
int map[99][99],visited[99][99],n;
vector<int> unitcnt;
int table[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
int
check(int x, int y) {
    return x>=0 and x<n and \
           y>=0 and y<n and \
           map[y][x] and !visited[y][x];
}
int cnt=0;
void
dfs(int x, int y) {
    int nx,ny;
    cnt++;
    visited[y][x]=1;
    map[y][x]=0;
    for(int i=0;i<4;i++) {
        nx=x+table[i][0],ny=y+table[i][1];
        if(check(nx,ny)) {
            dfs(nx,ny);
        }
    }
}
int
main() {
    string buf;
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> buf;
        for(int j=0;j<n;j++) {
            map[j][i]=buf[j]-'0';
 }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(check(j,i)) {
                dfs(j,i);
                unitcnt.push_back(cnt);
                cnt=0;
            }
        }
    }
    std::sort(unitcnt.begin(),unitcnt.end());
    cout << unitcnt.size() << "\n";
    for(auto i : unitcnt) {
        cout << i << "\n";
    }
}
