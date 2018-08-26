#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
vector<vector<int>> jobs;
int n,a,b,max,sum;
void go(int day,vector<int> cur) {
    if(day<n) {
        go(day+1,cur);
    }
    else {
        for(auto i : cur) {
            sum+=jobs[i][1];
        }
        max=max>sum?max:sum;
        sum=0;
        return;
    }
    if(day+jobs[day][0]<=n) {
        cur.push_back(day);
        go(day+jobs[day][0],cur);
    }
    else {
        go(day+1,cur);
    }
}
int
main() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> a >> b;
        jobs.push_back({a,b});
    }
    go(0,{});
    cout << max << "\n";
}
