#include <bits/stdc++.h>
using namespace std;

bool solve(string s, int n) {
    vector<bool> a(n);
    for (int i = 0; i < n; ++i) a[i] = s[i]-'0';
    for (int i = 0; i < n-1; ++i) {
        if (a[i]) {
            a[i] = !a[i];
            a[i+1] = !a[i+1];
            if (i+2 <= n-1) a[i+2] = !a[i+2];
        }
    }
    if (a[n-1]) {
        if ((n-1)%3 == 0 || (n-1)%3 == 2) return 1;
        else return 0;
    }
    return 1;
}

int main() {
    int n; cin>>n;
    string s; cin>>s;
    if (n==1) {
        cout<<"Yes"<<endl;
        return 0;
    }
    int ans = solve(s,n);
    reverse(s.begin(),s.end());
    ans |= solve(s,n);
    if (ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
