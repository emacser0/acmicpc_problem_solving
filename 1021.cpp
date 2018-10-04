#include <iostream>
#include <array>
#include <vector>
#include <deque>
using std::cin;
using std::cout;
using std::array;
using std::vector;
using std::deque;
deque<int> queue;
vector<int> list;
int front=0,rear=0,n,m,t,rcnt,lcnt;
void
go(int i) {
    if(i==front) {
        queue.erase(queue.begin()+front);
    }
    else if(i<front) {
        rcnt++;
        front=(front+1)%queue.size();
        rear=(rear+1)%queue.size();
    }
    else {
        lcnt++;
        front=(front-1)%queue.size();
        rear=(rear-1)%queue.size();
    }
}
int
main() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        queue.push_back(i);
    }
    rear=n-1;
    for(int i=0;i<m;i++) {
        cin >> t;
        list.push_back(t);
    }
}
