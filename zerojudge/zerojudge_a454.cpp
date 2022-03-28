#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    int n;
    while(t--) {
        cin>>n;
        vector <vector <int> > node(n+1);
        vector <int> days(n+1);
        vector <int> enter(n+1,0);
        for (int i = 1; i <= n; ++i) {
            int d, k; cin>>d>>k;
            days[i] = d;
            for (int j = 1; j <= k; ++j) {
                int id; cin>>id;
                enter[id]++;
                node[i].push_back(id);
            }
        }

    }
}