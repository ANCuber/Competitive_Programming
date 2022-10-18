#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

map <char,int> mp;
int n;

bool cmp(const string &a, const string &b) {
    for (int i = 0; i < min(a.size(),b.size()); ++i) {
        if (a[i] == b[i]) continue;
        if (mp[a[i]] < mp[b[i]]) return true;
        else return false;
    }
    return a.size()<b.size();
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c = 1; 
    cin>>n;
    vector <string> arr(n);
    for (int i = 0; i < n; ++i) cin>>arr[i];
    for (int i = 0; i < 13; ++i) {
        mp['a'+i] = c++;
        if(i != 12) mp['z'-i] = c++;
    }
    mp['n'] = 26;
    //for (char i = 'a'; i <= 'z'; ++i) cout<<mp[i]<<' ';
    //cout<<endl;
    sort(arr.begin(),arr.end(),cmp);
    for (auto i : arr) cout<<i<<endl;
    return 0;
}
