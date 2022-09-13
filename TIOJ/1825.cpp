#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string x; cin>>x;
    vector < pii > a(26,{0,0});
    for (int i = 0; i < x.size(); ++i) {
        if (a[x[i]-'A'].first) {
            a[x[i]-'A'].second = i+1;
        } else {
            a[x[i]-'A'].first = i+1;
        }
    }
    char out = 'A';
    for (int i = 0; i < 26; ++i) {
        if (a[i].first) {
            if (a[i].second) {
                cout<<char(out+i)<<':';
                cout<<a[i].first<<','<<a[i].second;
            } else {
                cout<<char(out+i)<<':';
                cout<<a[i].first<<','<<a[i].first;
            }
            cout<<endl;
        }
    }
    return 0;
}
