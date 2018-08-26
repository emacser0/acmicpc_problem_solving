#include <iostream>
#include <deque>
#include <array>
#include <functional>
using std::cin;
using std::cout;
using std::deque;
using std::array;
int map[199999],visited[199999],n,m,result;
int
check(int x) {
    return x>=0 and x<100001 and !visited[x];
}
auto forward=[](int x)->int{return x+1;};
auto backward=[](int x)->int{return x-1;};
auto teleport=[](int x)->int{return x*2;};
std::function<int(int)> table[3]={forward,backward,teleport};
void
bfs() {
    deque<array<int,2>> queue;
    array<int,2> t;
    int nx;
    queue.push_back({n,-1});
    for(;queue.size()>0;) {
        t=queue.front();
        t[1]++;
        if(t[0]==m) {
            result=t[1];
            return;
        }
        for(int i=0;i<3;i++) {
            nx=table[i](t[0]);
            if(check(nx)) {
                visited[nx]=1;
                queue.push_back({nx,t[1]});
            }
        }
        queue.pop_front();
    }
}
int
main() {
    cin >> n >> m;
    bfs();
    cout << result << "\n";
}
