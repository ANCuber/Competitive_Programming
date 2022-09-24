#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    map<char,int> mp;
    mp['+']=0, mp['*']=1, mp['!']=2;
    while(cin>>s && s[0] != 'E') {
        stack<char,vector<char> > op; 
        stack<int,vector<int> > num;
        for (auto i : s) {
            if (i=='+' || i=='*' || i=='!') {
                while(!op.empty() && mp[op.top()] > mp[i]) {
                    if (op.top()=='!') {
                        int tmp = num.top();
                        num.pop();
                        num.push(!tmp);
                    } else if (op.top()=='*') {
                        int a = num.top(), b;
                        num.pop();
                        b = num.top();
                        num.pop();
                        num.push(a&b);
                    }
                    op.pop();
                }
                op.push(i);
            } else {
                num.push(i-'0');
            }
        }
        while(!op.empty()) {
            if (op.top()=='!') {
                int tmp = num.top();
                num.pop();
                num.push(!tmp);
            } else if (op.top()=='*') {
                int a = num.top(), b;
                num.pop();
                b = num.top();
                num.pop();
                num.push(a&b);
            } else {
                int a = num.top(), b;
                num.pop();
                b = num.top();
                num.pop();
                num.push(a|b);
            }
            op.pop();
        }
        cout<<num.top()<<endl;
    }
    return 0;
}
