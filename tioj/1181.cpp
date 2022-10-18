#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    char x;
    map<char,int> mp;
    mp['R'] = 0;
    mp['G'] = 1;
    mp['B'] = 2;
    mp['Y'] = 3;
    mp['P'] = 4;
    while(t--) {
        bitset<5> v;
        v.reset();
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 6; ++j) {
                cin>>x;
                if (x == '.' || x == 'X') continue;
                v[mp[x]] = true;
            }
        }
        cout<<v.count()<<endl;
    }
    return 0;
}
