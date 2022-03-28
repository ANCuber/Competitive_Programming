#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    for (int l = 1; l <= t; l++) {
        int n; cin>>n;
        bool decider = 1;
        deque <int> Brail;
        stack <int> station;
        for (int i = 0; i < n; i++) {
            int x; cin>>x;
            Brail.push_back(x);
        }
        int train = 1;
        for (int i = 1; i <= n; i++) {
            if (station.empty()) {
                station.push(train);
            }
            while (station.top() != Brail.front()) {
                if (train == n) {
                    decider = 0;
                    cout<<"No\n";
                    break;
                }else{
                    station.push(++train);
                } 
            }
            if (decider == 1) {
                Brail.pop_front();
                station.pop();
            } else {
                break;
            }
            if (i == n) cout<<"Yes\n";
        }
    }
}