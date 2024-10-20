#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    stack <long long> pipe;
    for (int i = 1; i <= n; i++) {
        long long a; cin>>a;
        if (a < 0) {
            if (pipe.empty() || a + pipe.top() != 0) {
                cout<<"lose light light\n";
                return 0;
            } else {
                pipe.pop();
            }
        } else {
            pipe.push(a);
        }
    }
    if (!pipe.empty()) cout<<"lose light light\n";
    else cout<<"weed\n";
    return 0;
}