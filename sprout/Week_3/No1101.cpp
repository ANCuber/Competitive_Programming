#include <bits/stdc++.h>
using namespace std;

int controller = 0;

void dfs(int now, int last, int lastcolor, vector <vector<int> > &student, vector <int> &color) {
    if (lastcolor == color[now]) {
        controller = 1;
        return;
    } else if (!color[now]){
        color[now] = 3-lastcolor;
    } else {
        return;
    }
    for (int i = 0; i < student[now].size(); ++i) {
        if (student[now][i] == last) continue;
        dfs(student[now][i],now,color[now],student,color);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        controller = 0;
        int n, m; cin>>n>>m;
        int a, b;
        vector <int> color(n,0);
        vector <vector<int> > student(n);
        while(m--) {
            cin>>a>>b;
            student[a].push_back(b);
            student[b].push_back(a);
        }
        dfs(0,-1,1,student,color);
        if (controller) {
            cout<<"RAINBOW.\n";
        } else {
            cout<<"NORMAL.\n";
        }
    }
    return 0;
}