#include <iostream>
#include <vector>
#include <array>
using std::cin;
using std::cout;
using std::vector;
using std::array;
int n;
vector<int> primes={2};
array<int,1000001> primecheck;
void
init_primecheck() {
    primecheck.fill(1);
    primecheck[1]=false;
}
void
calc_prime(int n) {
    for(int i=2;(i*i)<=n;i++) {
        if(primecheck[i]) {
            for(int j=i*i;j<=n;j+=i) {
                primecheck[j]=false;
            }
        }
    }
    for(int i=primes.back()+1;i<=n;i++) {
        if(primecheck[i]) {
            primes.push_back(i);
        }
    }
}
void
print_goldbach(int a, int b, int n) {
    printf("%d = %d + %d\n",n,a,b);
}
void
goldbach(int n) {
    for(int i=1;i<n;i+=2) {
        if(primecheck[i]&&primecheck[n-i]) {
            print_goldbach(i,n-i,n);
            return;
        }
    }
}

int
main() {
    init_primecheck();
    calc_prime(1000001);
    for(;;) {
        scanf("%d",&n);
        if(n==0) {
            return 0;
        }
        goldbach(n);
    }
}
