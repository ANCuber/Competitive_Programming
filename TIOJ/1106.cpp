#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string x;
    int lf, dep, mx;
    while(cin>>x && x != "x") {
        vector<int> ary(1000005,0);
        lf = dep = mx = 0;
        stack<char> stk;
        int crdp = 0;
        int ay = 0;
        for (auto i : x) {
            if (i == '(') {
                stk.push(i);
                ary[crdp]++;
                crdp++;
            } else if (i == ')') {
                while(stk.top() != '(') {
                    stk.pop();
                    lf++;
                }
                stk.pop();
                ary[crdp] = 0;
                crdp--;
            } else {
                stk.push(i);
                ary[crdp]++;
            }
            if (crdp) mx = max(mx,ary[crdp]);
            dep = max(dep,crdp);
        }
        lf += stk.size();
        dep++;
        cout<<lf<<' '<<dep<<' '<<mx<<endl;
    }
    return 0;
}
