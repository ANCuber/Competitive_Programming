#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector <int> arr(n+1);
    vector <vector<int> > pos(500005);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        pos[arr[i]].push_back(i);
    }
    
    while(q--) {

    }
}