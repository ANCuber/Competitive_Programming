#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int graph[n][n];
        for (int i = 0; i < n-1; ++i) {
            graph[i][i] = 0;
            for (int j = 1; j <= n-i-1; ++j) {
                int d; cin>>d;
                graph[i][i+j] = d;
                graph[i+j][i] = d;
            }
        }
        graph[n-1][n-1] = 0;
        
    }
}