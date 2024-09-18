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
vector<double> f;
vector<double> fp;

double evalf(double x){
    double r = 0;
    for(int i=0;i<n;i++){
        r*=x;
        r+=f[i];
    }
    return r;
}
double evalfp(double x){
    double r=0;
    for(int i=0;i<n-1;i++){
        r*=x;
        r+=fp[i];
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    double k;
    while(cin>>k){
        f.push_back(k); 
    }
    n = f.size(); 
    for(int i=0;i<n-1;i++){
        fp.push_back(f[i]*(n-1-i));
    }
    double ans=0;
    for(int i=0;i<10000;i++){
        ans = ans - (evalf(ans)/evalfp(ans)); 
    }
    cout<<setprecision(2)<<fixed<<ans<<"\n";
}
