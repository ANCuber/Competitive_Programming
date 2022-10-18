#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin>>n>>m;
    int B[n+1];
    for (int i = 1; i <= n; ++i) {
        cin>>B[i];
    }
    int id = 1;
    vector<int> s(n+5);
    int stk = 0;
    for (int i = 1; i <= n; ++i) {
        if (B[id] == i) {
            id++;
            int ctrl = 1;
            while(ctrl) {
                int rng = min(m+1,stk);
                if (rng < 1) break;
                for (int j = 1; j <= rng; ++j) {
                    if (s[stk-j] == B[id]) {
                        for (int k = stk-j; k < stk-1; ++k) {
                            s[k] = s[k+1];
                        }
                        stk--;
                        id++;
                        break;
                    }
                    if (j == rng) ctrl = 0;
                }
            }
        } else {
            int ctrl = 1;
            while(ctrl) {
                int rng = min(m+1,stk);
                if (rng < 1) break;
                for (int j = 1; j <= rng; ++j) {
                    if (s[stk-j] == B[id]) {
                        for (int k = stk-j; k < stk-1; ++k) {
                            s[k] = s[k+1];
                        }
                        stk--;
                        id++;
                        break;
                    }
                    if (j == rng) ctrl = 0;
                }
            }
            s[stk++] = i;
        }
        //for (int j = 0; j < stk; ++j) cout<<s[j]<<' ';
        //cout<<"#"<<id-1<<endl;
    }
    if (id == n+1) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
