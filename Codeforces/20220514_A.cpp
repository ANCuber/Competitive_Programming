#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    int t; cin>>t;
    while(t--) {
        long long n; cin>>n;
        if (n & 1 || n < 4) {
            cout<<-1<<endl;
            continue;
        }
        n >>= 1;
        long long two = n/2;
        long long x = two;
        long long three = n/3;
        int r = n%3;
        long long y;
        if (r == 1) {
            y = three+1;
        } else if (r == 2) {
            y = three+1;
        } else {
            y = three;
        }
        cout<<y<<' '<<x<<endl;
    }
    return 0;
}