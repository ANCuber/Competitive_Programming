#include <bits/stdc++.h>
using namespace std;

int dx[4] = {+1,-1,+0,+0};
int dy[4] = {+0,+0,+1,-1};

struct position{
    int x, y;
    int count;
};

int main() {
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        position cat;
        cat.count = 0;
        vector <vector <char> > graph(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char x; cin>>x;
                graph[i].push_back(x);
                if (x == 'K') {
                    cat.x = i;
                    cat.y = j;
                }
            }
        }
        queue <position> q;
        q.push(cat);
        int controller = 0;
        while(!q.empty()) {
            position now = q.front();
            position next;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                if (graph[now.x+dx[i]][now.y+dy[i]] == '.') {
                    next.x = now.x+dx[i];
                    next.y = now.y+dy[i];
                    next.count = now.count+1;
                    q.push(next);
                    graph[now.x+dx[i]][now.y+dy[i]] = '#';
                } else if (graph[now.x+dx[i]][now.y+dy[i]] == '@') {
                    cout<<now.count+1<<'\n';
                    controller = 1;
                    break;
                }
            }
            if (controller == 1) break;
        }
        if (controller == 0) cout<<"= =\""<<'\n';
    }
    return 0;
}