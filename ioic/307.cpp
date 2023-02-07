#pragma GCC optimize("Ofast,unroll-loops,O3")
//#pragma GCC optimize("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
#pragma pack(1)
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define MAXN 100005
using namespace std;
//using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> order_multiset;
//typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> order_set;
int isNotPrime[MAXN+1];
int mu[MAXN+1],phi[MAXN+1];
int need[MAXN+5],vis[MAXN+5];
vector<int>prime;
inline void build(){
    isNotPrime[0]=isNotPrime[1]=true;
    mu[1]=1; phi[1]=1;
    for (int i=2;i<=MAXN;i++){
        if (!isNotPrime[i]){
            isNotPrime[i]=i;
            prime.push_back(i);
            mu[i]=-1;
            phi[i]=i-1;
        }
        for (auto j:prime){
            int t=i*j;
            if (t>MAXN) break;
            isNotPrime[t]=j;
            if (i%j==0){
                mu[t]=0;
                phi[t]=phi[i]*j;
                break;
            }
            else{
                mu[t]=-mu[i];
                phi[t]=phi[i]*(j-1);
            }
        }
    }
}
void solve(int n){
    int now=1,cnt=0;
    if (n==1){
        need[n]=-1;
        return;
    }
    vector<int>path;
    while (!vis[now]){
        path.push_back(now);
        vis[now]=++cnt;
        now=now*10;
        now%=n;
    }
    if (vis[now]==1){
        need[n]=cnt;
    }
    else need[n]=-1;
    for (auto i:path)
        vis[i]=0;
}
int lcm(int a,int b){
    return a/__gcd(a,b)*b;
}
signed main(){
    fast
    build();
    for (auto i:prime)
        solve(i);
    int q; cin>>q;
    while (q--){
        int n; cin>>n;
        if (n==1){
            cout<<-1<<'\n';
            continue;
        }
        map<int,int>mp;
        while (n!=1){
            mp[isNotPrime[n]]++;
            n/=isNotPrime[n];
        }
        int ans=1;
        for (auto i:mp){
            if (need[i.x]==-1){
                ans=-1;
                break;
            }
            ans=lcm(need[i.x]*i.y,ans);
        }
        cout<<ans<<'\n';
    }
}
