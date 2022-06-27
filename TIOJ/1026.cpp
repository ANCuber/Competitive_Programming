#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    int d; cin>>d;
    bitset <32> pace(0);
    int i = 0;
    for (;d; ++i) {
        pace[i] = d&1;
        d >>= 1;
    }
    cout<<i<<endl;
    for (int j = 1; j < i; ++j) {
        if (!pace[j]) {
            pace[j] = 1;
            pace[j-1] = 0;
        }
    }
    for (int j = 0; j < i; ++j) {
        if (pace[j]) cout<<'+';
        else cout<<'-';
    }
    cout<<endl;
    return 0;
}