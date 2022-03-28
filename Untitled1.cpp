#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    bool arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    int low = 0; int high = n-1;
    int guess = (high+low)/2;
    int director = 0;
    while(high > low+1) {
        guess = (high+low)/2;
        if (!arr[guess]) {
            low = guess;
        } else {
            high = guess;
            director = 1;           
        }
    }
    if (director) cout<<high<<'\n';
    else cout<<-1<<'\n';
    return 0;
}