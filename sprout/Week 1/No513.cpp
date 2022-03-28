#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector <unsigned long long> tall(n);
    for (int i = 0; i < n; ++i) {
        int a; cin>>a;
        tall[i] = a;
    }
    stack <int> stk;
    vector <unsigned long long> area(n,0);
    for (int i = 0; i < n; ++i) {
        while (!stk.empty()) {
            if (tall[i] <= tall[stk.top()]) {
                stk.pop();
            } else  break;
        }
        if (stk.empty()) {
            area[i] += (i+1)*tall[i];
        } else {
            area[i] += (i-stk.top())*tall[i];
        }
        stk.push(i);
    }
    stack <int> stk2;
    reverse(tall.begin(), tall.end());
    reverse(area.begin(), area.end());
    unsigned long long max = 0;
    for (int i = 0; i < n; ++i) {
        while (!stk2.empty()) {
            if (tall[i] <= tall[stk2.top()]) {
                stk2.pop();
            } else  break;
        }
        if (stk2.empty()) {
            area[i] += (i)*tall[i];
        } else {
            area[i] += (i-stk2.top()-1)*tall[i];
        }
        stk2.push(i);
        if (max < area[i]) max = area[i];
    }
    cout<<max<<'\n';
    return 0;
}