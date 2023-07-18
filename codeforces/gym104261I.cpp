#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
int arr[105][105];
pair<int,int> loc[10005];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
bitset<10005> vis;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m;cin>>n>>m;     
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
            loc[arr[i][j]] = {i,j};
        }
    }
    int maxn = 0;
    for(int i=1;i<=n*m;i++){
        vis.reset();
        int cnt = 0;
        priority_queue<int,vector<int>,greater<int>> touch;
        vis[i]=1;
        touch.push(i);
        while(touch.size()){
            cnt++;
            int cur = touch.top();
        //    cout<<cur<<"\n";
            touch.pop();
            int x = loc[cur].first;
            int y = loc[cur].second;
            for(int k=0;k<4;k++){
               if(vis[arr[x+dx[k]][y+dy[k]]]) continue;
               if(arr[x+dx[k]][y+dy[k]]<cur) continue;
               //cout<<arr[x+dx[k]][y+dy[k]]<<" ";
               touch.push(arr[x+dx[k]][y+dy[k]]);
               vis[arr[x+dx[k]][y+dy[k]]]=1;
            }
        }
        maxn = max(cnt,maxn);
    }
    cout<<maxn<<"\n";
    return 0;
}
