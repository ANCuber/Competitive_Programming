#include <bits/stdc++.h>
using namespace std;

int n;
vector <queue<int> > backet(10);//536

void radix_sort(vector <int> &arr) {
    long long now = 1;
    for (int l = 0;  l < 10; ++l) {
        for (auto i : arr) {
            int index = (i/now)%10;
            backet[index].push(i);
        }
        int ctrl = 0;//index of arr
        for (int i = 0; i < 10; ++i) {
            while(!backet[i].empty()) {
                arr[ctrl] = backet[i].front();
                backet[i].pop();
                ctrl++;
            }
        }
        now *= 10;
    }
}

int main() {
    cin>>n;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    radix_sort(arr);
    for (auto i : arr) cout<<i<<' ';
    cout<<'\n';
    return 0;
}