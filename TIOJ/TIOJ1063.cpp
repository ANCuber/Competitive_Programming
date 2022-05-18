#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin>>m>>n;
    int graph[m][n];
    vector <int> height(n,0);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>graph[i][j];
            if (!i && graph[i][j]) height[j] = 1;
        }
    }//input
    ll ans = 0;
    //cout<<endl;
    for (int i = 0; i < m; ++i) {
        vector <int> left;
        vector <int> right;
        vector <ll> curans(n,0);
        for (int j = 0; j < n; ++j) {
            while(!left.empty()) {
                if (height[j] <= height[left.back()]) {
                    left.pop_back();
                } else {
                    break;
                }
            }
            if (left.empty()) {
                curans[j] += (j+1)*height[j];
            } else {
                curans[j] += (j-left.back())*height[j];
            }
            left.push_back(j);
        }
        for (int j = n-1; j >= 0; --j) {
            while (!right.empty()) {
                if (height[j] <= height[right.back()]) {
                    right.pop_back();
                } else {
                    break;
                }
            }
            if (right.empty()) {
                curans[j] += (n-1-j)*height[j];
            } else {
                curans[j] += (right.back()-j-1)*height[j];
            }
            right.push_back(j);
            ans = max(ans,curans[j]);
            //cout<<curans[j]<<' ';
        }
        if (i != m-1) {
            for (int j = 0; j < n; ++j) {
                if (graph[i+1][j]) height[j]++;
                else height[j] = 0;
            }
        }
        //cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}