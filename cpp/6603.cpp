#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
int k=1,t;
vector<int> s;
void go(int index, vector<int> v) {
    if(index<k) {
        v.push_back(s[index]);
        go(index+1,v);
        v.pop_back();
        go(index+1,v);
    }
    else {
        if(v.size()!=6) {
            return;
        }
        for(auto i : v) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
int
main() {
    for(;k>0;) {
        cin >> k;
        for(int i=0;i<k;i++) {
            cin >> t;
            s.push_back(t);
        }
        go(0,{});
        cout << "\n";
        s.clear();
    }
}
