#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

#define lb(x) (x & -x)

struct BIT {
    int N;
    vector<int> node;

    BIT(int n): N(n + 1), node(n + 1) {}
    
    void modify(int i, int dx) {
        for (; i < N; i += lb(i)) node[i] += dx;
    }

    int query(int i) {
        int answer = 0;
        for (; i; i -= lb(i)) answer += node[i];
        return answer;
    }

    int get(int l, int r) {
        return query(r) - query(l);
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int N, M;
    cin >> N >> M;

    vector<int> v(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    vector<int> ans(M + 2);
    BIT bit(N + 1);

    map<int, int> mp;
    for (int i = 1; i <= N; i++) {
        auto it = mp.find(v[i]);
        int lst = 0;
        if (it != mp.end()) {
            lst = it->second;   
        }
        
        mp[v[i]] = i;

        int cnt = bit.get(lst, i);
        ans[1]++;
        ans[cnt + 1]--;
        if (it != mp.end()) bit.modify(lst, -1);
        bit.modify(i, 1);
    }

    for (int i = 1; i <= M; i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << ' ';
    }

    return 0;
}
