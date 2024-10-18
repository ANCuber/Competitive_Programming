#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

bool is_prime(int x) {
    if (x == 2) return 1;
    if (x%2 == 0 || x == 1) return 0;
    for (int i = 3; i*i <= x; i += 2) {
        if (x%i == 0) return 0;
    }
    return 1;
}

signed main() {
    int a, b; cin>>a>>b;
    if (is_prime(abs(a-b))) {
        cout<<2<<endl;
        cout<<a<<' '<<b<<endl;
    } else if (is_prime(a+b)) {
        cout<<3<<endl;
        cout<<a<<' '<<(a+b)<<' '<<b<<endl;
    } else if (is_prime(a-2) && is_prime(b-2)) {
        cout<<3<<endl;
        cout<<a<<' '<<2<<' '<<b<<endl;
    } else if (is_prime(a+2) && is_prime(abs(a+2-b))) {
        cout<<3<<endl;
        cout<<a<<' '<<a+2<<' '<<b<<endl;
    } else if (is_prime(a-2) && is_prime(abs(a-2-b))) {
        cout<<3<<endl;
        cout<<a<<' '<<a-2<<' '<<b<<endl;
    } else {
        cout<<-1<<endl;
    }
    return 0;
}
