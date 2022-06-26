#include <bits/stdc++.h>
using namespace std;

int k;

vector <int> node;
vector <int> stk(6);

void print() {
    for (int i = 0; i < 6; ++i) {
        if (i != 0) cout<<' ';
        cout<<stk[i];
    }
    cout<<'\n';
}

void dfs(int depth, int nowindex) {
    stk[depth] = node[nowindex];
    if (depth == 5) {
        print();
    } else {
        for (int i = nowindex+1; i < k; ++i) {
            dfs(depth+1,i);
        }
    }
}

int main() {
    int l = 0;
    while(cin>>k) {
        if (!k) break;
        if (l) cout<<'\n';
        l = 1;
        node.clear();
        for (int i = 0; i < k; ++i) {
            int a; cin>>a;
            node.push_back(a);
        }
        sort (node.begin(), node.end());
        for (int i = 0; i < k; ++i) {
            dfs(0,i);
        }
    }
    return 0;
}