#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    char x; cin>>x;
    string N; cin>>N;
    N = '9'+N;
    int ptr = N.size()-1;
    deque<int> K;
    for (int i = N.size()-1; i >= 0; --i) {
        if (N[i] == '1') {
            if (N[i-1] == '1') continue;
            if (i == ptr) {
                //cout<<i<<' '<<ptr<<endl;
                K.push_front(1);
            } else {
                for (int j = ptr; j > i; --j) {
                    if (j == ptr) K.push_front((10-(N[i]-'0')));
                    else K.push_front((10-(N[i]-'0')-1));
                }
            }
            ptr = i+1;
        }
    }
    int flag = 0;
    if (K.empty()) {
        cout<<"0\n";
        return 0;
    }
    for (int i = 0; i < K.size(); ++i) {
        if (K[i] != 0) flag = 1;
        if (!flag) continue;
        cout<<K[i];
    }
    cout<<'\n';
    return 0;
}
