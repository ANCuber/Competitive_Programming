#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    string x; 
    map <char,int> mp;
    mp['+'] = mp['-'] = 1;
    mp['*'] = 2;

    while(n--) {
        cin>>x;
        
        for (int i = 0; i < x.size(); ++i) {
            if (x[i] == '(') {
                
            } else if (x[i] == ')') {
                
            } else if (x[i]=='+' || x[i]=='-' || x[i]=='*') {
                
            } else {
                ll a = 0;
                while(i<x.size() && x[i]-'0'>=0 && x[i]-'0'<=9) {
                    a += (x[i]-'0');
                    a *= 10;
                    i++;
                }
                i--;
                a /= 10;
                num.push_back(a);
            }
        }

        ll cur = 0;
        while(ope.size()) {
            if (ope.front() == '+') {
                cur = num.front();
                num.pop_front();
                cur += num.front();
                num.pop_front();
                num.push_front(cur);
            } else if (ope.front() == '-') {
                cur = num.front();
                num.pop_front();
                cur -= num.front();
                num.pop_front();
                num.push_front(cur);
            } else {
                cur = num.front();
                num.pop_front();
                cur *= num.front();
                num.pop_front();
                num.push_front(cur);
            }
            ope.pop();
        }
        cout<<num.front()<<' '<<num.back()<<endl;
    }
    return 0;
}
