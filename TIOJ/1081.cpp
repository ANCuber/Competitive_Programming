#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int m, n;
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

void bfs(vector<vector<int> > &graph, int i, int j) {
    //cout<<"pass";
    graph[i][j] = 0;
    for (int k = 0; k < 8; ++k) {
        if (i+dx[k]<m && i+dx[k]>=0 && j+dy[k]>=0 && j+dy[k]<n) {
            if (graph[i+dx[k]][j+dy[k]]) {
                bfs(graph,i+dx[k],j+dy[k]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>m>>n && m && n) {
        ll ans = 0;
        vector<vector<int> > graph(m,vector<int>(n));
        for (int i = 0; i < m; ++i) {
            string x; cin>>x;
            for (int j = 0; j < n; ++j) {
                if (x[j] == '0') graph[i][j] = 0;
                else graph[i][j] = 1;
            }
        }
        //cout<<"pass";
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][j]) {
                    ans++;
                    bfs(graph,i,j);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}