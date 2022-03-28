#include <bits/stdc++.h>
using namespace std;

int ans;
int dx[9] = {+1,-1,0,0,+1,-1,+1,-1,0};
int dy[9] = {0,0,+1,-1,+1,+1,-1,-1,0};

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
    if (ans >= 2) return;
    if (i == 8 && j == 8 && graph[8][8] && allow(graph,8,8)) {
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

int check(vector <vector<int> > graph) {
    vector <int> horizon(10,0);
    vector <int> vertical(10,0);
    for (int i = 0; i < 9; ++i) {
        fill(horizon.begin(),horizon.end(),0);
        fill(vertical.begin(),vertical.end(),0);
        for (int j = 0; j < 9; ++j) {
            horizon[graph[i][j]]++;
            if (horizon[graph[i][j]] >= 2 && graph[i][j]) return 0;
            vertical[graph[j][i]]++;
            if (vertical[graph[j][i]] >= 2 && graph[j][i]) return 0;
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            vector <int> count(10,0);
            for (int k = 3*i; k < 3*i+3; ++k) {
                for (int l = 3*j; l < 3*j+3; ++l) {
                    count[graph[k][l]]++;
                    if (count[graph[k][l]] > 1 && graph[k][l]) return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector <vector<int> > graph(9, vector<int> (9,0));
    int ctrl = 1;
    while(true) {
        ans = 0;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cin>>graph[i][j];
            }
        }
        if (cin.fail()) break;
        cout<<"Case "<<ctrl<<": ";
        if (!check(graph)) {
            cout<<"Illegal.\n";
            ans = -1;
        }
        if (ans != -1) solve(0,0,graph);
        if (ans>=2) cout<<"Ambiguous.\n";
        else if (ans==1) cout<<"Unique.\n";
        else if (ans==0) cout<<"Impossible.\n";
        ctrl++;
    }
    return 0;
}