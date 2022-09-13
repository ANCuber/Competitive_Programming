#include <bits/stdc++.h>
using namespace std;

int ans;
int dx[9] = {+1,-1,0,0,+1,-1,+1,-1,0};
int dy[9] = {0,0,+1,-1,+1,+1,-1,-1,0};

void print_graph(vector <vector<int> > &graph) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j){
            cout<<graph[i][j];
        }
    }
    cout<<'\n';
}

bool allow(vector <vector<int> > &graph, int i, int j) {
    for (int di = 0; di < 9; ++di) {
        if (di == i) continue;
        if (graph[di][j] == graph[i][j]) return 0;
    }
    for (int dj = 0; dj < 9; ++dj) {
        if (dj == j) continue;
        if (graph[i][dj] == graph[i][j]) return 0;
    }
    int x = (i/3)*3+1, y = (j/3)*3+1;
    for (int k = 0; k < 9; ++k) {
        if (!graph[x+dx[k]][y+dy[k]]) continue;
        for (int l = 0; l < 9; ++l) {
            if (k != l && (graph[x+dx[k]][y+dy[k]] == graph[x+dx[l]][y+dy[l]])) return 0;
        }
    }
    return 1;
}


void solve(int i, int j, vector <vector<int> > &graph) {
    if (ans >= 1) return;
    if (i == 8 && j == 8 && graph[8][8] && allow(graph,8,8)) {
        print_graph(graph);
        ans++;
        return;
    }
    if (graph[i][j]) {
        if (j == 8) {
            solve(i+1,0,graph);
        } else {
            solve(i,j+1,graph);
        }
    } else {
        for (int k = 1; k <= 9; ++k) {
            graph[i][j] = k;
            if (allow(graph,i,j)) {
                if (i == 8 && j == 8) {
                    print_graph(graph);
                    ans++;
                    graph[i][j] = 0;
                    return;
                }
                if (j == 8) {
                    solve(i+1,0,graph);
                } else {
                    solve(i,j+1,graph);
                }
            }
        }
        graph[i][j] = 0;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector <vector<int> > graph(9, vector<int> (9,0));
    int t; cin>>t;
    while(t--) {
        string x; cin>>x;
        int k = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (x[k] == '.') {
                    graph[i][j] = 0;
                } else {
                    graph[i][j] = x[k]-'0';
                }
                k++;
            }
        }
        ans = 0;
        solve(0,0,graph);
        if (!ans) cout<<"No solution.\n";
    }
    return 0;
}