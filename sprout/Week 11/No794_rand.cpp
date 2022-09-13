#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector <int> arr(n+1);
    vector <vector<int> > pos(500005);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        pos[arr[i]].push_back(i);
    }
    srand(time(NULL));
    while(q--) {
        int lb, rb;
        cin>>lb>>rb;
        int len = rb-lb+1;
        int count = 0;
        bool ctrl = 0;
        for (int i = 0; i < 30; ++i) {
            int cur = lb+rand()%len;
            auto l = lower_bound(pos[arr[cur]].begin(),pos[arr[cur]].end(),lb);
            auto r = upper_bound(pos[arr[cur]].begin(),pos[arr[cur]].end(),rb);
            count = r-l;
            if (count > len/2) {
                ctrl = true;
                cout<<arr[cur]<<endl;
                break;
            }
        }
        if (!ctrl) cout<<ctrl<<endl;
    }
    return 0;
}