#include <bits/stdc++.h>
using namespace std;

struct position{
    int x, y;
    int time;
};

int dx[4] = {0,0,+1,-1};
int dy[4] = {+1,-1,0,0};

int n, m, p, q, a, b;

int main() {
    cin>>n>>m>>p>>q>>a>>b;
    vector <vector<int> > graph(n+1,vector<int>(m+1,0));
    vector <vector<int> > visited(n+1,vector<int>(m+1,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>graph[i][j];
        }
    }
    queue <position> q;
    position initial;
    initial.x = 1; initial.y = 1;
    initial.time = 0;
    q.push(initial);
    while(!q.empty()) {
        position now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            
        }
        for (int i = 0; i < 4; ++i) {

        }
    }
    
}