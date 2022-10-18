#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

string ans[5] = {"0","WIN","LOSE","WIN","WIN"};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string n;
    while(cin>>n) {
        reverse(n.begin(),n.end());
        int flag = 0;
        for (int i = 1; i < n.size(); ++i) {
            if (n[i] != '0') {
                flag = 1;
                break;
            }
        }
        if (!flag && n[0] == '0') break;

        if ((n[0]-'0') % 2) cout<<"LOSE"<<' ';
        else cout<<"WIN"<<' ';

        if (flag) {
            if ((n[0]-'0') & 1) {
                cout<<"LOSE"<<endl;
            } else {
                cout<<"WIN"<<endl;
            }
        } else {
            if (n[0]-'0' <= 4) {
                cout<<ans[n[0]-'0']<<endl;
            } else if ((n[0]-'0') & 1) {
                cout<<"LOSE"<<endl;
            } else {
                cout<<"WIN"<<endl;
            }
        }
    }
    return 0;
}
