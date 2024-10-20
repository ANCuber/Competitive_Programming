#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector <vector<int> > tree;
vector <int> c;
int fd = 0;

void search(int last, int now, vector <int> &arr) {
    //cout<<"pass";
    for (int i = 0; i < tree[now].size(); ++i) {
        if (tree[now][i] == last) continue;
        arr.push_back(c[tree[now][i]]);
        search(now,tree[now][i],arr);
    }
    arr.push_back(c[now]);
}

void dfs(int last, int now, int target, vector <int> &arr) {
    if (fd) return;
    if (now == target) {
        fd = 1;
        search(now,target,arr);
        return;
    }
    for (int i = 0; i < tree[now].size(); ++i) {
        if (tree[now][i] == last) continue;
        if (tree[now][i] == target) {
            fd = 1;
            search(now,target,arr);
            break;
        }
        dfs(now,tree[now][i],target,arr);
    }
}

int main() {
    int n, q; cin>>n>>q;
    tree.resize(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b; cin>>a>>b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin>>c[i];
    }
    for (int i = 0; i < q; ++i) {
        fd =0;
        int r; cin>>r;
        vector <int> arr;
        dfs(-1,0,r-1,arr);
        int minnum = INT_MAX;
        int maxnum = -1;
        /* for (int i = 0; i < arr.size(); ++i) {
            cout<<arr[i]<<' ';
        }
        cout<<endl; */
        for (int i = 0; i < arr.size(); ++i) {
            minnum = min(minnum,arr[i]);
            maxnum = max(maxnum,arr[i]);
        }
        cout<<maxnum-minnum<<endl;
    }
    return 0;
}