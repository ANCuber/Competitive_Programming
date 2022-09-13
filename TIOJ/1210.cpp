#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

//Havel(Canisters) theorem
string ans[2] = {"No","Yes"};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin>>n && n) {
        vector<int> a(n);
        for (auto& i : a) cin>>i;
        bool ctrl = 1;
        for (int i = 0; i < n; ++i) {
            sort(a.begin()+i,a.end(),greater<int>());
            int dg = a[i];
            if (dg > n-i-1) {
                ctrl = 0;
                break;
            }
            for (int j = 1; j <= dg && ctrl; ++j) {
                if (a[i+j] <= 0) ctrl = 0; 
                a[i+j]--;
            }
            if (!ctrl) break;
        }
        cout<<ans[ctrl]<<endl;
    }
    return 0;
}
