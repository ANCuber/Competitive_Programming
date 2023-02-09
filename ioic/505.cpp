#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

vector<int> is(1000005,1);
vector<int> pri;

void findprime() {
    is[0] = is[1] = 0;
    for (int i = 2; i <= 1e6; ++i) {
        if (!is[i]) continue;
        pri.pb(i);
        for (int j = i+i; j <= 1e6; j += i) {
            is[j] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    findprime();
    while(t--) {
        int x, y; cin>>x>>y;
        int a = x/__gcd(x,y), b = y/__gcd(x,y);
        int flag = 0;
        /*for (int i = 0;i < pri.size(); ++i) {
            if (flag) break;
            for (int j = i+1; j < pri.size(); ++j) {
                if (pri[i]*pri[j]*a  == b*(pri[i]+pri[j])) {
                    cout<<"Find:"<<pri[i]<<' '<<pri[j]<<endl;
                    flag = 1;
                    break;
                }
            }
        }*/
        if (a == 1 && b == 1) {
            cout<<2<<' '<<2<<endl;
            continue;
        } else if (a == 2) {
            cout<<b<<' '<<b<<endl;
        } else {
            cout<<(a+(int)(sqrt(a*a-4*b)))/2<<' '<<(a-(int)(sqrt(a*a-4*b)))/2<<endl;
        }
    }
    
    
    return 0;
}
