#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin>>m>>n;
    int graph[m][n];
    vector <int> height(n);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>graph[i][j];
            if (!i && graph[i][j]) height[j] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        vector <int> left;
        vector <int> right;
        vector <int> curans(n,0);
        for (int j = 0; j < n; ++j) {
            if (!height[j]) {
                left.clear();
                continue;
            }
            while(!left.empty()){
                if (height[left.back()] > height[j]) {
                    left.pop_back();
                } else {
                    break;
                }
            }
            if (left.empty()) {
                curans[j] += height[j];
                continue;
            }
            int id = left.size()-1;
            while(id >= 0 && height[left[id]] == height[j]) {
                id--;
            }
            curans[j] += (j-left[id]+1)*height[j];
            left.push_back(j);
        }
        for (int j = n-1; j >= 0; --j) {
            if (!height[j]) {
                right.clear();
                continue;
            }
            while(!right.empty()){
                if (height[right.back()] > height[j]) {
                    right.pop_back();
                } else {
                    break;
                }
            }
            if (right.empty()) {
                continue;
            }
            int id = right.size()-1;
            while(id >= 0 && height[right[id]] == height[j]) {
                id--;
            }
            curans[j] += (right[id]-j)*height[j];
            left.push_back(j);
        }
        ans = max(*max_element(curans.begin(),curans.end()),ans);
    }
    cout<<ans<<endl;
    return 0;
}