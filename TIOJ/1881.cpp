#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>

int cal(int a, int b, char ope) {
    if (ope == '+') {
        return a+b;
    } else if (ope == '-') {
        return b-a;
    } else {
        return a*b;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    string x; 
    map <char,int> mp;
    mp['+'] = mp['-'] = 1;
    mp['*'] = 2;
    while(n--) {
        cin>>x;
        stack <char,vector<char> > stk;
        stack <int,vector<int> > num;
        
        for (int i = 0; i < x.size(); ++i) {
            if (x[i] == '(') {
                stk.push(x[i]);
            } else if (x[i] == ')') {
                while(stk.top() != '(') {
                    int a = num.top();
                    num.pop();
                    int b = num.top();
                    num.pop();
                    num.push(cal(a,b,stk.top()));
                    stk.pop();
                }
                stk.pop();
            } else if (x[i]=='+' || x[i] =='-' || x[i]=='*') {
                while(stk.size() && mp[x[i]] <= mp[stk.top()]) {
                    int a = num.top();
                    num.pop();
                    int b = num.top();
                    num.pop();
                    num.push(cal(a,b,stk.top()));
                    stk.pop();
                }
                stk.push(x[i]);
            } else {
                int a = 0;
                while(i < x.size() && x[i]-'0' >= 0 && x[i]-'0' <= 9) {
                    a += (x[i]-'0');
                    a *= 10;
                    ++i;
                }
                a /= 10;
                --i;
                num.push(a);
            }
        }
        while(stk.size()) {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            num.push(cal(a,b,stk.top()));
            stk.pop();
        }
        cout<<num.top()<<endl;
    }
    return 0;
}
