#include <iostream>
#include <vector>
using std::cin;
using std::cout;
std::vector<int> data,sum;
int n,s,t,cnt;
void recsum(int cur) {
    int size=sum.size();
    for(int i=0;i<size;i++) {
        sum.push_back(data[cur]+sum[i]);
    }
    sum.push_back(data[cur]);
    if(cur<n-1) {
        recsum(cur+1);
    }
}
int
main() {
    cin >> n >> s;
    for(int i=0;i<n;i++) {
        cin >> t;
        data.push_back(t);
    }
    recsum(0);
    for(int i=sum.size()-1;i>=0;i--) {
        if(sum[i]==s) {
            cnt++;
        }
    }
    cout << cnt << "\n";
}
