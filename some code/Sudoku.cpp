#include <bits/stdc++.h>
using namespace std;

int ans;
int dx[9] = {+1,-1,0,0,+1,-1,+1,-1,0};//delta i
int dy[9] = {0,0,+1,-1,+1,+1,-1,-1,0};//delta j

void print_graph(vector <vector<int> > &graph) {//output whole answer
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

bool allow(vector <vector<int> > &graph, int i, int j) {//whether or not the DFS is permissible
    for (int di = 0; di < 9; ++di) {//column
        if (di == i) continue;
        if (graph[di][j] == graph[i][j]) return 0;
    }
    for (int dj = 0; dj < 9; ++dj) {//row
        if (dj == j) continue;
        if (graph[i][dj] == graph[i][j]) return 0;
    }
    int x = (i/3)*3, y = (j/3)*3;
    vector <int> count(10,0);
    for (int k = x; k < x+3; ++k) {//3x3 square
        for (int l = y; l < y+3; ++l) {
            count[graph[k][l]]++;
            if (count[graph[k][l]] > 1 && graph[k][l]) return 0;
        }
    }
    return 1;
}//this function can be better, but I am lazy X)


void solve(int i, int j, vector <vector<int> > &graph) {
    if (i == 8 && j == 8 && graph[8][8] && allow(graph,8,8)) {//find a solution
        print_graph(graph);
        ans++;
        return;
    }
    if (graph[i][j]) {//the square is already set
        if (j == 8) {//new line or not
            solve(i+1,0,graph);
        } else {
            solve(i,j+1,graph);
        }
    } else {//the square has no value
        for (int k = 1; k <= 9; ++k) {//dfs
            graph[i][j] = k;//give a value
            if (allow(graph,i,j)) {
                if (i == 8 && j == 8) {//find a solution
                    print_graph(graph);
                    ans++;
                    graph[i][j] = 0;
                    return;
                }
                if (j == 8) {//new line or not
                    solve(i+1,0,graph);
                } else {
                    solve(i,j+1,graph);
                }
            }
        }
        graph[i][j] = 0;//reset the value
    }
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout<<"Please enter the problem."<<endl;
    vector <vector<int> > graph(9, vector<int> (9,0));
    for (int i = 0; i < 9; ++i) {//input a problem(0s mean blank)
        for (int j = 0; j < 9; ++j) {
            cin>>graph[i][j];
        }
    }
    cout<<'\n';
    ans = 0;
    solve(0,0,graph);//dfs and output the solution(s)
    if (ans>=2) cout<<"There are a total of "<<ans<<" solutions.\n";//many solutions
    else if (ans==1) cout<<"There is only one solution.\n";//only one solution
    else if (ans==0) cout<<"Impossible or illegal case!\n";//the case can't be solved
    return 0;
}

/* Example Input
1 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
7 9 8 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 7 9 2 1 4 3 6 5
5 3 2 9 4 1 6 7 8
6 4 1 5 7 8 9 3 2
0 0 0 0 0 0 0 0 0
 */