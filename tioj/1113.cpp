#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int dep;

void dfs(vector<int> &arr, vector<int> v, vector<int> vis, int d) {
    for (int i = 0; i < dep; ++i) {
        if (vis[i]) continue;
        v.push_back(arr[i]);
        vis[i] = 1;
        if (d == dep) {
            for (auto j : v) {
                cout<<char('a'+j);
            }
            cout<<endl;
        } else dfs(arr,v,vis,d+1);
        v.pop_back();
        vis[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string x;
    while(cin>>x && x != "E") {
        dep = x.size();
        vector<int> arr(dep);
        vector<int> vis(dep,0);
        vector<int> v;
        for (int i = 0; i < dep; ++i) {
            arr[i] = x[i]-'a';
        }
        sort(arr.begin(),arr.end());
        dfs(arr,v,vis,1);
        cout<<endl;
    }
    return 0;
}
