#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin>>n>>m;
    map <string,int> mp;
    for (int i = 0; i < n; ++i) {
        string input; cin>>input;
        if (mp.find(input) == mp.end()) mp[input] = 1;
        else mp[input]++;
    }
    for (int i = 0; i < m; ++i) {
        string q; cin>>q;
        if (mp.find(q) == mp.end()) cout<<0<<endl;
        else cout<<mp[q]<<endl;
    } 
    return 0;
}