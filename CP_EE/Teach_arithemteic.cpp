#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

inline int Precedence(char op) {
    if (op == '+') return 1;
    if (op == '-') return 2;
    if (op == '*') return 3;
    if (op == '/') return 4;
    if (op == '^') return 5;
    return -1;
}

int pow(int a, int x) {
    int bs = a, ret = 1;
    while(x) {
        if (x&1) ret = ret*bs%7;
        bs = bs*bs%7;
        x >>= 1;
    }
    return ret;
}

char Calculate(char a, char b, char op) {
    int ca = a-'0', cb = b-'0', ret;
    if (op == '+') ret = (ca+cb)%7;
    if (op == '-') ret = (ca-cb+7)%7;
    if (op == '*') ret = (ca*cb)%7;
    if (op == '/') ret = (ca*pow(cb,5))%7;
    if (op == '^') ret = pow(ca,cb);
    return char(ret+'0');
}

void TeachArithemteic(string Expression) {
    cout<<Expression<<'\n';
    int cnt = Expression.size();
    while(cnt > 1) {
        int tmp = -1, ln = -1, rn = -1, pop = 0, pren, brl, brr;
        for (int i = 0; i < Expression.size(); ++i) {
            if (Expression[i] == ' ') continue;
            if (Expression[i] == '(') {
                tmp = -1, ln = -1, rn = -1, pop = 0;
                brl = i;
                continue;
            }
            if (Expression[i] == ')') {
                brr = i;
                break;
            }
            if (Precedence(Expression[i]) > pop) {
                pop = Precedence(Expression[i]);
                tmp = i;
                ln = pren, rn = -1;
            } else if (Precedence(Expression[i]) < 0) {
                pren = i;
                if (pop && rn < 0) rn = i;
            }
        }
        if (tmp == -1) {
            Expression[brr] = Expression[brl] = ' ';
            cout<<Expression<<'\n';
        } else {
            for (int i = 0; i < Expression.size(); ++i) {
                if (i == ln) cout<<'\\';
                else if (i == rn) cout<<'/';
                else if (i > ln && i < rn) cout<<'_';
                else cout<<' ';
            }
            cout<<'\n';
            char Result = Calculate(Expression[ln],Expression[rn],Expression[tmp]);
            Expression[tmp] = Result;
            Expression[ln] = Expression[rn] = ' ';
            cout<<Expression<<'\n';
        }
        cnt -= 2;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin>>s;
    TeachArithemteic(s);
    return 0;
}
