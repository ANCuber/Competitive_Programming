#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    while (1) {
        if (cin.fail()) break;
        cin>>a;
        deque <bool> ans;
        while (a != 0) {
            ans.push_front(a%2);
            a /= 2;
        }
        for (int i:ans) cout<<i;
        cout<<'\n'; 
    }
    return 0;
}