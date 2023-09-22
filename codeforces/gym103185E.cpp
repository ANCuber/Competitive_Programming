#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;cin>>n;      
    vector<int> arr(n+1,0);
    vector<int> left(n+1,0);
    vector<int> right(n+1,n+1);
    vector<int> ans(n+5,0);
    for(int i=1;i<=n;i++) cin>>arr[i];
    stack<int> stk; 
    for(int i=1;i<=n;i++){
        while(stk.size()){
            if(arr[stk.top()]<=arr[i])  stk.pop();
            else break;
        }
        if(stk.size()) left[i]=stk.top();
        stk.push(i);
    }
    while(stk.size()) stk.pop();
    for(int i=n;i>=1;i--){
        while(stk.size()){
            if(arr[stk.top()]<=arr[i]) stk.pop();
            else break;
        }
        if(stk.size())  right[i]=stk.top();
        stk.push(i);
    }
    for(int i=1;i<=n;i++){
        if(left[i]==0){ans[1]+=1;ans[i]-=1;}
        else{
            int k = ((i-left[i])/2);
            if((i-left[i])%2==0) k--;
            ans[i-k]+=1;
            ans[i]-=1;
        }
        if(right[i]==n+1){ans[i+1]+=1;ans[n+1]-=1;}
        else{
            int k = (right[i]-i)/2;
            if((right[i]-i)%2==0) k--;
            ans[i+1]+=1;
            ans[i+k+1]-=1;
        }
    }
    for(int i=1;i<=n;i++){
       ans[i]+=ans[i-1];
       cout<<ans[i]<<" " ;
    }
    cout<<"\n";
    return 0;
}
