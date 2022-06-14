#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector <int> ans;
ll a = 0;
int n;

void solve(int x, vector <int> tmp) {
    vector <int> ori = tmp;
    for (int i = 0; i < tmp.size()-1; ++i) {
        if ((tmp[i]+tmp[i+1]) <= x && x%(tmp[i]+tmp[i+1]) == 0) {
            if (x == n) {
                a++;
                tmp.insert(tmp.begin()+i+1,x);
                for (int j = 0; j <= n; ++j) {
                    if (tmp[j] > ans[j]) {
                        for (int k = 0; k <= n; ++k) {
                            ans[k] = tmp[k];
                        }
                        break;
                    }
                    if (tmp[j] < ans[j]) break;
                }
                tmp = ori;
            } else {
                tmp.insert(tmp.begin()+i+1,x);
                solve(x+1,tmp);
                tmp = ori;
            }
        }
    }
}

int main() {
    cin>>n;
    if (n == 1) {
        cout<<1<<endl;
        cout<<0<<' '<<1<<endl;
        return 0;
    }
    ans.assign(n+1,0);
    vector <int> g;
    g.push_back(0);
    g.push_back(1);
    solve(2,g);
    if (a) {
        cout<<a<<endl;
        for (int i = 0; i <= n; ++i) {
            if (i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    } else {
        cout<<0<<endl;
    }
    return 0;
}