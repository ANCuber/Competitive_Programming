#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include "lib1168.h"
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

p_q <int> mx, mxrm;
p_q <int,vector<int>,greater<int> > mn, mnrm;

void pop_big() {
    while(!mxrm.empty() && mx.top() == mxrm.top()) {
        mxrm.pop();
        mx.pop();
    }
    mnrm.push(mx.top());
    mx.pop();
}

void pop_small() {
    while(!mnrm.empty() && mn.top() == mnrm.top()) {
        mnrm.pop();
        mn.pop();
    }
    mxrm.push(mn.top());
    mn.pop();

}

void push(int s) {
    mx.push(s);
    mn.push(s);
}

int big() {
    while(!mxrm.empty() && mx.top() == mxrm.top()) {
        mxrm.pop();
        mx.pop();
    }
    return mx.top();
}

int small() {
    while(!mnrm.empty() && mn.top() == mnrm.top()) {
        mnrm.pop();
        mn.pop();
    }
    return mn.top();
}

/*int main() {
    int n; cin>>n;
    int cmd;
    while(n--) {
        cin>>cmd;
        if (cmd == 1) {
            pop_big();
        } else if (cmd == 2) {
            pop_small();
        } else if (cmd == 3) {
            int s; cin>>s;
            push(s);
        } else if (cmd == 4) {
            cout<<big()<<endl;
        } else {
            cout<<small()<<endl;
        }
    }
    return 0;
}*/
