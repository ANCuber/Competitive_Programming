#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main () {
    int n; cin>>n;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    vector <int> recd(n,0);
    for (int i = 0; i < n; ++i) {
        if(++recd[arr[i]-1]>1 || arr[i] > n || arr[i] < 1) {
            cout<<"fail nember:"<<arr[i]<<endl;
            return 0;
        }
    }
    bool ctrl = 0;
    for (int i = 0; i <= n-3; ++i) {
        for (int j = i+1; j <= n-2; j++) {
            for (int k = j+1; k <= n-1; k++) {
                if (arr[k]-arr[j] == arr[j]-arr[i]) {
                    cout<<"fail array:";
                    cout<<arr[i]<<' '<<arr[j]<<' '<<arr[k]<<endl;
                    ctrl = 1;
                }
            }
        }
    }
    if (!ctrl) cout<<"Accepted"<<endl;
    return 0;
}