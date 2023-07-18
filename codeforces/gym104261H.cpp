#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
//#define endl '\n'
#define pb push_back

unordered_map<string,int> num;
bitset<305> pos[305];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;cin>>n;      
    int largest[n]={0};
    vector<string> numton;
    for(int i=0;i<n;i++){
        string s;cin>>s;
        num[s]=i;
        numton.push_back(s);
    }
    for(int i=0;i<305;i++) pos[i].set();
    int q;cin>>q;
    set<int> has;
    while(q--){
       int m,w;cin>>m>>w; 
       has.insert(w);
       bitset<305> k;
       for(int i=0;i<m;i++){
         string a;cin>>a;
         k[num[a]]=1;
         largest[num[a]] = max(largest[num[a]],w);
       }
       pos[w]&=k;
       //cout<<w<<" ";
       //for(int i=0;i<n;i++) cout<<pos[w][i];
       //cout<<endl;
    }
    int order[n];
    for(int i=0;i<n;i++) order[i]=i;
    sort(order,order+n,[&](const int a,const int b){return largest[a]>largest[b];});
    //for(int i=0;i<n;i++)  cout<<largest[i]<<" ";
    //cout<<endl;
    //for(int i=0;i<n;i++) cout<<order[i]<<" ";
    //cout<<endl;
    int what[n]={0};
    bitset<305> rank;
    for(auto w : has){
        pair<int,int> minn = {1e9,-1};    
        for(int i=0;i<n;i++){
           if(pos[w][i]) minn = min(minn,{largest[i],i});
        }
        what[minn.second] = w;
        rank[w]=1;
    }
    int head = 0;
    for(int i=n;i>=1;i--){
        if(rank[i]) continue;
        while(head<n && what[order[head]]) head++;
        what[order[head]]=i;
    }
    //for(int i=0;i<n;i++){
     //   cout<<what[i]<<"\n";
    //}
    sort(numton.begin(),numton.end(),[&](const string a,const string b){return what[num[a]]<what[num[b]];});
    for(auto i : numton) cout<<i<<" ";
    cout<<endl;
    return 0;
}
