#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

const int MAX = 1e6;

bitset <MAX> ht, cur;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    int id;
    for (int i = 0; i < m; ++i) {
        cin>>id;
        ht[i] = id;
    }
    vector<int> arr(m+1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m; ++j) {
            cin>>arr[j];
        }
        vector<int> now = arr;
        id = m-1;
        for (int j = m; j > 0; --j) {
            if (now[j] >= now[j-1]) {
                cur[id--] = 1;
            } else {
                cur[id--] = 0;
            }
            now[j-1] = abs(arr[j]-arr[j-1]);
        }

        int flag = 1;
        for (int j = 0; j < m; ++j) {
            if (ht[j] != cur[j]) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            for (int j = 0; j <= m; ++j) {
                if (j) cout<<' ';
                cout<<arr[j];
            }
            cout<<endl;
        }
    }
    return 0;
}
