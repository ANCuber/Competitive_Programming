#include <bits/stdc++.h>
using namespace std;

int main() {
    string a; cin>>a;
    int strsize = a.size()/2;
    int fullsize = a.size();
    for (int i = 0; i < strsize; i++) {
        if (a[i] != a[fullsize - i -1]) {
            cout<<"no\n";
            return 0;
        }
    }
    cout<<"yes\n";
    return 0;
}