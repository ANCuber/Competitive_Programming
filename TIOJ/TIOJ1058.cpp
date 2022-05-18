#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    string a, b;
    cin>>a>>b;
    int lena = 0, lenb = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == '.') lena = i;
    }
    for (int i = 0; i < b.size(); ++i) {
        if (b[i] == '.') lenb = i;
    }
    if (!lena) {
        lena = a.size();
    }
    if (!lenb) {
        lenb = b.size();
    }
    if (lena > lenb) {
        cout<<a<<endl;
        return 0;
    }
    if (lenb > lena) {
        cout<<b<<endl;
        return 0;
    }
    for (int i = 0; i < min(a.size(),b.size()); ++i) {
        if (a[i] > b[i]) {
            cout<<a<<endl;
            return 0;
        }
        if (b[i] > a[i]) {
            cout<<b<<endl;
            return 0;
        }
    }
    if (a.size() > b.size()) cout<<a<<endl;
    else cout<<b<<endl;
    return 0;
}