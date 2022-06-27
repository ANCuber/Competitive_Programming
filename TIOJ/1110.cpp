#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int k; cin>>k;
        string x; cin>>x;
        int maxn = 0;
        vector <int> al(27,0);
        for (int i = 0; i < k; ++i) {
            int cur = x[i]-'a';
            maxn = max(maxn,++al[cur]);
        }
        for (int i = 0; i < 26; ++i) {
            if (al[i] == maxn) {
                char out = 'a'+i;
                cout<<out;
            }
        }
        cout<<endl;
    }
    return 0;
}