#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
    int n; cin>>n;
    vector <int> cows(n);
    for (int i = 0; i < n; ++i) {
        cin>>cows[i];
    }
    stack <int> stk;
    stk.push(n-1);
    deque <int> ans;
    ans.push_front(0);
    for (int i = n-2; i >= 0; --i) {
        while(!stk.empty() && cows[stk.top()] <= cows[i]) {
            stk.pop();
        }
        if (stk.empty()) {
            ans.push_front(n-i-1);
        } else {
            ans.push_front(stk.top()-i);
        }
        stk.push(i);
    }
    for (auto i : ans) {
        cout<<i<<endl;
    }
    return 0;
}