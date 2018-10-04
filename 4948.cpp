#include <iostream>
using std::cin;
using std::cout;
int isnotprime[250000];
void
Eratosthenes(int n) {
    for(int i=2;(i*i)<=n;i++) {
        if(!isnotprime[i]) {
            for(int j=(i*i);j<=n;j+=i) {
                isnotprime[j]=1;
            }
        }
    }
}
int
main() {
    int n=1,cnt;
    Eratosthenes(249000);
    while(1) {
        cin >> n;
        if(n==0) {
            break;
        }
        cnt=0;
        for(int i=n+1;i<=n*2;i++) {
            if(!isnotprime[i]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
