#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string fm; cin>>fm;
    stack <char,vector<char> > stk;
    map <char,int> mp;
    mp['+'] = mp['-'] = 1;
    mp['*'] = mp['/'] = 2;
    for (int i = 0; i < fm.size(); ++i) {
        if (fm[i]!='('&&fm[i]!=')'&&fm[i]!='+'&&fm[i]!='-'&&fm[i]!='/'&&fm[i]!='*') {
            cout<<fm[i];
        } else {
            if (fm[i] == '(') {
                stk.push(fm[i]);
            } else if (fm[i] == ')') {
                while(stk.top() != '(') {
                    cout<<stk.top();
                    stk.pop();
                }
                stk.pop();
            } else {
                while(stk.size() && mp[fm[i]] <= mp[stk.top()]) {
                    cout<<stk.top();
                    stk.pop();
                }
                stk.push(fm[i]);
            }
        }
    }
    while(stk.size()) {
        cout<<stk.top();
        stk.pop();
    }
    cout<<endl;
    return 0;
}
