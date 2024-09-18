#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue
int n;
struct seg{
    struct node{
        int s=0;
        int len=1;
        bool tag=0;
        void rev(){
           s = len-s; 
           tag=!tag;
        };
        void combine(node &a,node &b){
            s = a.s+b.s; 
            len = a.len+b.len;
            if(tag){
                rev(); 
                tag=1;
            }
        }
    };

    vector<node> arr; 
    void init(){
        arr.resize(2*n); 
        string st;cin>>st;
        for(int i=0;i<n;i++) arr[i+n].s = (st[i]=='1');
        for(int i=n-1;i>=1;i--) arr[i].combine(arr[2*i],arr[2*i+1]);
    }

    void pull(int ind){
        if(ind==1) return;
        pull(ind>>1);
        ind>>=1;
        if(arr[ind].tag){
            arr[2*ind].rev();
            arr[2*ind+1].rev();
            arr[ind].tag=0;
        }
    }
    void push(int ind){
        ind>>=1;
        while(ind){
            arr[ind].combine(arr[2*ind],arr[2*ind+1]) ;
            ind>>=1;
        }
    }
    void modify(int l,int r){
        l+=n;r+=n;
        pull(l);pull(r-1); 
        int tl=l;int tr=r;
        while(l<r){
            if(l%2) arr[l++].rev();
            if(r%2) arr[--r].rev();
            l>>=1;r>>=1;
        }
        push(tl);push(tr-1);
    }
    int query(int l,int r){
        l+=n;r+=n;
        pull(l);pull(r-1);
        int ans=0;
        while(l<r){
            if(l%2) ans+=arr[l++].s;
            if(r%2) ans+=arr[--r].s;
            l>>=1;r>>=1;
        }
        return ans;
    }

    void print(){
        for(int i=1;i<2*n;i++){
            cout<<i<<" "<<arr[i].s<<"\n";
        }
    }
};
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int q;cin>>n>>q;
    seg segtree;
    segtree.init();
    while(q--){
        int type;cin>>type;
        int l,r;cin>>l>>r;
        l--;
        if(type==1){
            segtree.modify(l,r);  
        }else{
            int ones = segtree.query(l,r);
            ll ans = 1LL*((r-l)-ones)*ones;
            cout<<ans<<"\n";
        }
    }
}
