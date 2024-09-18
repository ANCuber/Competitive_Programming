#pragma target("popcnt")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<ll,ll> pii;
#define F first
#define S second
#define pb push_back
#define pq priority_queue
#define all(x) (x).begin(),(x).end()
#define bug(x) cerr << (x) << ' '
#define debug(x) cerr << #x << " = " << x << '\n'
#define yn(x) cout << (x==1?"Yes\n":"No\n")
#define PI 3.14159265358979323
#define Ststone ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

//basic
const ll max_n=5e5+10,max_int=2147483647,mod1=1e9+7,mod2=998244353;
ll t,n,m,h,w,a,b,c,d;
bool ok;
char cc;
///str s,s1,s2;
//set<ll> ss,ss1,ss2;
vector<ll> v[max_n],v1,v2,now;
//vector<pii> ed[max_n];
//priority_queue<ll> pri[max_n];
//map<ll,ll> mp;
ll arr[20],vis[20],k;
set<ll> s;

bool chk(){
    bool ok = 1;
    for(ll i=0;i<n;i++){
        for(ll j=i+2;j<n;j++){
            ll mx = 0,mn = 48763;
            for(ll k=i;k<=j;k++){
                mx = max(mx,arr[k]);
                mn = min(mn,arr[k]);
            }
            if(abs(arr[i]-arr[j])==mx-mn) ok = 0;
        }
    }
    return ok;
}

void out(){
    if(!chk()) return;
    for(ll i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void dfs(ll now){
    if(now==n){
        out();
    }
    else{
        for(ll i=1;i<=n;i++){
            if(!vis[i]){
                arr[now] = i;
                vis[i] = 1;
                dfs(now+1);
                vis[i] = 0;
            }
        }
    }
}

void solve(){
    cin >> n;
    dfs(0);
}

int main(){
    Ststone;
    //cin >> t;
    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    t = 1;
    while(t--){
        solve();
    }
}

/*

1 2  +
2 1  -

1 3 2 (2 1) 2
2 1 3 (1 2) 1 -
2 3 1 (2 1) 2 +
3 1 2 (1 2) 1

1 4 2 3 (3 1 2) 1 4 1
2 1 4 3 (1 3 2) 2 1 2
2 3 1 4 (2 1 3) 3 2 1
2 4 1 3 (3 1 2) 4 4 1
3 1 4 2 (1 3 2) 5 1 2
3 2 4 1 (2 3 1) 6 3 2
3 4 1 2 (3 1 2) 7 4 1
4 1 3 2 (1 3 2) 8 1 2

1 5 2 4 3 (4 1 3 2) 8 1 2
2 1 5 3 4 (1 4 2 3) 1 
2 3 1 5 4 (2 1 4 3) 2
2 4 1 5 3 (3 1 4 2) 5
2 5 1 4 3 (4 1 3 2) 8
3 1 5 2 4 (1 4 2 3) 1
3 2 4 1 5 (2 3 1 4) 3
3 2 5 1 4 (2 4 1 3) 4
3 4 1 5 2 (3 1 4 2) 5
3 4 2 5 1 (3 2 4 1) 6
3 5 1 4 2 (4 1 3 2) 8
4 1 5 2 3 (1 4 2 3) 1
4 2 5 1 3 (2 4 1 3) 4
4 3 5 1 2 (3 4 1 2) 7
4 5 1 3 2 (4 1 3 2) 8
5 1 4 2 3 (1 4 2 3) 1


1 6 2 5 3 4 
2 1 6 3 5 4 () 1
2 3 1 6 4 5 () 2
2 4 1 6 3 5 () 6
2 5 1 6 3 4 () 12
2 6 1 5 3 4 () 16
3 1 6 2 5 4 
3 2 4 1 6 5 
3 2 5 1 6 4 
3 2 6 1 5 4 
3 4 1 6 2 5 
3 4 2 5 1 6 
3 4 2 6 1 5 
3 5 1 6 2 4 
3 5 2 6 1 4 
3 6 1 5 2 4 
4 1 6 2 5 3 
4 2 5 1 6 3 
4 2 6 1 5 3 
4 3 5 1 6 2 
4 3 5 2 6 1 
4 3 6 1 5 2 
4 5 1 6 2 3 
4 5 2 6 1 3 
4 5 3 6 1 2 
4 6 1 5 2 3 
5 1 6 2 4 3 
5 2 6 1 4 3 
5 3 6 1 4 2 
5 4 6 1 3 2 
5 6 1 4 2 3 
6 1 5 2 4 3 

*/

