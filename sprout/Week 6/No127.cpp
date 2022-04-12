#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector <vector<int> > graph;

int GetVal (int p, int q) {
    return graph[p-1][q-1];
}

void Report(int x) {
    cout<<x<<endl;
}

void mysolve(int up,int down,int l, int r){
    if (down - up == 1) {
        int maxabl = INT_MIN;
        int maxid = -1;
        for (int i = l; i <= r; ++i) {
            int x = GetVal(up,i);
            if (x > maxabl) {
               maxabl = x;
                maxid = i;
            }
        }
        Report(maxid);
        maxabl = INT_MIN;
        for (int i = l; i <= r; ++i) {
            int x = GetVal(down,i);
            if (x > maxabl) {
               maxabl = x;
                maxid = i;
            }
        }
        Report(maxid);
        return;
    } else if (down == up) {
        int maxabl = INT_MIN;
        int maxid = -1;
        for (int i = l; i <= r; ++i) {
            int x = GetVal(up,i);
            if (x > maxabl) {
               maxabl = x;
                maxid = i;
            }
        }
        Report(maxid);
        return;
    }
    int row = (down+up)>>1; 
    int maxabl = INT_MIN;
    int maxid = -1;
    for (int i = l; i <= r; ++i) {
        int x = GetVal(row,i);
        if (x > maxabl) {
            maxabl = x;
            maxid = i;
        }
    }
    mysolve(up,row-1,l,maxid-1);
    Report(maxid);
    mysolve(row+1,down,maxid+1,r);
    return;
}

void solve (int n, int m) {
    mysolve(1,n,1,m);
}

int main() {
    int n,m;
    cin>>n>>m;
    graph.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j){
            int x; cin>>x;
            graph[i].push_back(x);
        }
    }
    solve(n,m);
    return 0;
}