#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

const int MAXN = 2e5+5;
pair<int,int> father[MAXN];
int arr[MAXN];

int query(int a){
    if(father[a].first==a) return a; 
    father[a]  = father[query(father[a].first)];
    return father[a].first;
}

void join(int a,int b){
    a = query(a);
    b = query(b);
    if(arr[a]>arr[b]) swap(a,b);
    father[a].second+=father[b].second;
    father[b] = father[a];
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;cin>>n;
    pair<int,int> seq[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        father[i]={i,1}; 
        seq[i] = {arr[i],i};
    }
    sort(seq,seq+n,greater<pair<int,int> > ());
    ll maxn = arr[seq[0].second];
    ll ans = arr[seq[0].second];
    for(int i=1;i<n;i++){
       int cur = seq[i].second;
       if(cur && arr[cur-1]>arr[cur]){
            int head = query(cur-1);
            ans-= 1LL*arr[father[head].first]*father[head].second;
            join(cur-1,cur);
       }
       if(cur!=n-1 && arr[cur+1]>=arr[cur]){
            int head = query(cur+1);
            ans-=1LL*arr[father[head].first]*father[head].second;
            join(cur+1,cur);       
       }
       int head = query(cur);
       ans+= 1LL*arr[father[head].first]*father[head].second;
       maxn = max(ans,maxn);
    }
    cout<<maxn<<"\n";
}
