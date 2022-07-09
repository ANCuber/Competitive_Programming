#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a;
    map <int,int> mp;
    pii cur;
    cur.first = cur.second = -1;
    while(cin>>a && a) {
        if (mp.find(a) == mp.end()) mp[a] = 1;
        else mp[a]++;
        if (mp[a] == cur.second && a < cur.first) {
            cur.first = a;
        } else if (mp[a] > cur.second) {
            cur.first = a;
            cur.second = mp[a];
        }
        cout<<cur.second<<' '<<cur.first<<endl;
    }
    return 0;
}
