#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    cin >> N;
    
    int counter = 0;

    vector<string> v(N);
    map<string, int> mp;
    for (auto& n: v) {
        cin >> n;
        mp[n] = counter++;
    }
    
    int gameCount;
    cin >> gameCount;
    
    vector<int> minimum(N);
    bitset<300> impossible[300];

    while (gameCount--) {
        int playerCount, winnerId;
        cin >> playerCount >> winnerId;

        vector<int> player(playerCount);
        string s;
        winnerId--;
        for (auto& n: player) {
            cin >> s;
            n = mp[s];
        }
        bitset<300> current;
        current.set();
        for (auto& n: player) current[n] = 0;
        impossible[winnerId] &= current;
    }

    return 0;
}
