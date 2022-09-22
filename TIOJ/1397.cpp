#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    while(cin>>n>>k) {
        string x; cin>>x;
        deque <int> q;
        int mn = 10, id = -1;
        for (int i = 0; i <= k; ++i) {
            if (mn > x[i]-'0' && x[i] != '0') {
                mn = x[i]-'0';
                id = i;
            }
        }
        cout<<mn;
        int lp = id+1, rp = k+1;
        for (int i = lp; i <= rp; ++i) {
            while(!q.empty() && x[q.back()] > x[i]) q.pop_back();
            q.push_back(i);
        }
        for (int i = 1; i < n-k; ++i) {
            while(!q.empty() && q.front() < lp) q.pop_front();
            cout<<x[q.front()];
            lp = q.front()+1;
            while(!q.empty() && x[q.back()] > x[rp+1]) q.pop_back();
            q.push_back(++rp);
        }
        cout<<endl;
    }
    
    return 0;
}
