#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;
int n,m;
vector<string> fishbun;
int
main() {
    string t;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> t;
        fishbun.push_back(t);
    }
    for(auto i : fishbun) {
        for(auto j=i.rbegin();j!=i.rend();j++) {
            cout << *(j);
        }
        cout << "\n";
    }
}
