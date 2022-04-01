#include <bits/stdc++.h>
using namespace std;

int b;
int ans = 0;

void count(int a, int i) {
    if (ans) return;
    if (a == b) {
        ans = i;
        return;
    }
    
}

int main() {
    int a; cin>>a>>b;
    cout<<ans<<'\n';
    return 0;
}