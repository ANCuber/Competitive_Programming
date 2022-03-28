#include <bits/stdc++.h>
using namespace std;

int ans;
int dx[9] = {+1,-1,0,0,+1,-1,+1,-1,0};
int dy[9] = {0,0,+1,-1,+1,+1,-1,-1,0};

void print_graph(vector <vector<int> > &graph) {
    cout<<"Answer #"<<ans+1<<":\n";
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j){
            if (j%3) cout<<' ';
            else cout<<'|';
            cout<<graph[i][j];
        }
        cout<<"|\n";
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
    int x = (i/3)*3, y = (j/3)*3;
    vector <int> count(10,0);
    for (int k = x; k < x+3; ++k) {
        for (int l = y; l < y+3; ++l) {
            count[graph[k][l]]++;
            if (count[graph[k][l]] > 1 && graph[k][l]) return 0;
        }
    }
    return 1;
}


void solve(int i, int j, vector <vector<int> > &graph) {
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
    cout<<"Please enter the problem."<<endl;
    vector <vector<int> > graph(9, vector<int> (9,0));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin>>graph[i][j];
        }
    }
    cout<<'\n';
    ans = 0;
    solve(0,0,graph);
    if (ans>=2) cout<<"There are a total of "<<ans<<" solutions.\n";
    else if (ans==1) cout<<"There is only one solution.\n";
    else if (ans==0) cout<<"Impossible or illegal case!\n";
    return 0;
}