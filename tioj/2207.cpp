#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;    
    vector<string> s(k);
    for (auto& i : s) cin>>i;
    if (k == 1) {
        for (auto i : s[0]) cout<<(i=='0');
    } else if (k == 2) {
        int a0 = 0, a1 = 0;
        for (int i = 0; i < n; ++i) {
            if (s[0][i] == s[1][i]) {
                cout<<'1'-s[0][i];
            } else {
                if(a0 == a1) {
                    cout<<s[0][i];
                    a1++;
                } else if (a0 < a1) {
                    cout<<s[1][i];
                    a0++;
                } else {
                    cout<<s[0][i];
                    a1++;
                }
            }
        }
    } else {
        int a[3] = {0,0,0}, x = 0, y = 0, z = 0;
        for (int i = 0; i < n; ++i) {
            if (s[0][i] == s[1][i] && s[1][i] == s[2][i]) continue;
            else if (s[0][i] == s[1][i]) a[0]++, a[1]++, z++; 
            else if (s[1][i] == s[2][i]) a[1]++, a[2]++, x++;
            else a[0]++, a[2]++, y++;
        }
        int p = min_element(a,a+3)-a;
        
        while(true) {
            bool flag = 0;
            for (int i = 0; i < 3; ++i) {
                if (i != p && a[i]-1 <= a[p]) flag = 1;
            }
            if (flag) break;
            if (p == 0) a[0]++,a[1]--,a[2]--,x--;
            else if (p == 1) a[0]--,a[1]++,a[2]--,y--;
            else a[0]--,a[1]--,a[2]++,z--;
        }

        for (int i = 0; i < n; ++i) {
            if (s[0][i] == s[1][i] && s[1][i] == s[2][i]) cout<<'1'-s[0][i];
            else if (s[0][i] == s[1][i]) cout<<(z?(z--,s[2][i]):s[0][i]);
            else if (s[1][i] == s[2][i]) cout<<(x?(x--,s[0][i]):s[1][i]);
            else cout<<(y?(y--,s[1][i]):s[0][i]);
        }
    }
    cout<<endl;

    return 0;
}
