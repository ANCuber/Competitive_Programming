#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int k; cin>>k;
    string s; cin>>s;
    vector<int> arr;
    int cnt = 0, pre = -1;
    for (int i = 0; i < s.size(); ++i) {
        int tmp = ((s[i]-'A')/26 == 0)*1;
        if (tmp == pre) {
            cnt++;
        } else {
            arr.push_back(cnt);
            cnt = 1;
        }
        pre = tmp;
    }
    if (cnt) arr.push_back(cnt);
    int ans = 0, cur = 0, flg = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > k && flg) {
            ans = max(ans,++cnt);
            cnt = 1;
            continue;
        } else if (arr[i] == k && flg) {
            cnt++;
        } else if (arr[i] >= k && !flg) {
            flg = 1;
            cnt = 1;
        } else {
            flg = 0;
            cnt = 0;
        }
        ans = max(ans,cnt);
    }
    cout<<ans*k<<'\n';
    return 0;
}
