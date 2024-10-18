#pragma GCC optimize("Ofast,unroll-loops,O3")
//#pragma GCC optimize("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//#pragma pack(1)
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define N 200005
using namespace std;
//using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> order_multiset;
//typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> order_set;
int last_centroid[N],dis[22][N];
int dep[N],fa[N],son[N],n,m;
bool vis[N];
vector<pii>g[N],point[N];
vector<int>idx[N],need[3];
struct Better_build_graph{
    int dis[600005],num=0;
    vector<pii>G[600005];
    void add_edge(int a,int b,int c){ G[a].push_back({b,c}); }
    void dijkstra(){
        for (int i=0;i<=num+2;i++)
            dis[i]=1e18;
        priority_queue<pii,vector<pii>,greater<pii> >pq;
        dis[2]=0; dis[3]=0;
        pq.push({dis[2],2});
        while (!pq.empty()){
            pii np=pq.top(); pq.pop();
            if (np.x!=dis[np.y]) continue;
            for (auto [i,c]:G[np.y]){
                if (dis[i]>np.x+c){
                    dis[i]=np.x+c;
                    pq.push({dis[i],i});
                }
            }
        }
    }
}dijk;
int get_size(int p,int lp){
    son[p]=1;
    for (auto [i,c]:g[p])
        if (!vis[i]&&i!=lp)
            son[p]+=get_size(i,p);
    return son[p];
}
int get_centroid(int p,int lp,int sz){
    for (auto [i,c]:g[p])
        if (!vis[i]&&i!=lp&&son[i]>sz/2)
            return get_centroid(i,p,sz);
    return p;
}
void dfs(int p,int lp,int mid,int depth){
    point[mid].push_back({dis[depth][p],p});
    for (auto [i,c]:g[p]){
        if (!vis[i]&&i!=lp){
            dis[depth][i]=dis[depth][p]+c;
            dfs(i,p,mid,depth);
        }
    }
}
void cut(int p,int last_mid,int depth){
    int now_size=get_size(p,last_mid);
    int mid=get_centroid(p,last_mid,now_size);
    vis[mid]=1; last_centroid[mid]=last_mid; dep[mid]=depth;
    dfs(mid,mid,mid,depth);
    sort(point[mid].begin(),point[mid].end());
    idx[mid].resize(point[mid].size()+3,0);
    dijk.num+=2; idx[mid][0]=dijk.num;
    dijk.add_edge(2*point[mid][0].y,dijk.num,0);
    dijk.add_edge(dijk.num|1,2*point[mid][0].y|1,0);
    for (int i=1;i<(int)point[mid].size();i++){
        dijk.num+=2; idx[mid][i]=dijk.num;
        dijk.add_edge(dijk.num|1,idx[mid][i-1]|1,0);
        dijk.add_edge(idx[mid][i-1],dijk.num,0);
        dijk.add_edge(point[mid][i].y*2,dijk.num,0);
        dijk.add_edge(dijk.num|1,point[mid][i].y*2|1,0);
    }
    for (auto [i,c]:g[mid])
        if (!vis[i])
            cut(i,mid,depth+1);
}
void jump(int mid,int p,int d,int num){
    if (mid<0||mid>n) return;
    if (dep[mid]>20){
        cout<<"NO\n";
        return;
    }
    pii now={d-dis[dep[mid]][p],(int)1e9};
    int np=upper_bound(point[mid].begin(),point[mid].end(),now)-point[mid].begin()-1;
    if (np>=0&&np<(int)point[mid].size())
        need[num].push_back(idx[mid][np]);
    jump(last_centroid[mid],p,d,num);
}
signed main(){
    fast
    cin>>n>>m;
    dijk.num=2*n+2;
    for (int i=0;i<=n;i++)
        dijk.add_edge(2*i|1,2*i,0);
    for (int i=1;i<=n;i++)
        cin>>fa[i];
    for (int i=1;i<=n;i++){
        int c; cin>>c;
        g[fa[i]].push_back({i,c});
        g[i].push_back({fa[i],c});
    }
    cut(0,-1,0);
    for (int i=1;i<=m;i++){
        need[0].clear(); need[1].clear();
        int u,d1,v,d2,c;
        cin>>u>>d1>>v>>d2>>c;
        jump(u,u,d1,0);
        jump(v,v,d2,1);
        for (auto j:need[0]){
            for (auto k:need[1]){
                dijk.add_edge(j,k|1,c);
                dijk.add_edge(k,j|1,c);
            }
        }
    }
    dijk.dijkstra();
    for (int i=1;i<=2*n+1;i+=2)
        cout<<dijk.dis[i]<<endl;
}
/*
0~5 -> 0,1 : 10
0,1,2 -> 3,0,1
5 -> 1,0,2 : 6
*/
