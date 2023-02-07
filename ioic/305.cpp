#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int cmb(int n, int k) {
    
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    string s; cin>>s;
    vector<int> dp(n+5,0);
    int left = 0, right = 0, ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') left++;
        else {
             
        }
    }
    
    return 0;
}
