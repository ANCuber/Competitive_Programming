#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue
#pragma GCC optimize("Ofast")

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string c; cin>>c;
    for (int i = 0; i < c.size(); ++i) {
        if (c[i] >= 'a' && c[i] <= 'z') {
            cout<<c[i];
            continue;
        }
        int len = 0;
        if (c[i+1] >= '0' && c[i+1] <= '9') {
            if (c[i+2] >= '0' && c[i+2] <= '9') {
                len = 100;
                ++i;
            } else {
                len = (c[i]-'0')*10+c[i+1]-'0';
            }
            ++i;
        } else {
            len = c[i]-'0';
        }
        i++;
        while(len--) cout<<c[i];
    }
    cout<<endl;
    return 0;
}
