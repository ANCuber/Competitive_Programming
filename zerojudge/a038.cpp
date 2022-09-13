#include <bits/stdc++.h>
using namespace std;

int main() {
    string x; cin>>x;
    int controller = 0;
    for (int i = x.size()-1; i >= 0; i--) {
        if (x[i] != '0') controller = 1;
        if (controller == 1) cout<<x[i];
        if (i == 0 && controller == 0) cout<<0;
    }
    cout<<endl;
    return 0;
}