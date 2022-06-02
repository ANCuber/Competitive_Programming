#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a;
    while(cin>>a) {
        if (a == "stop") break;
        cout<<"\\\\sqrt{"<<a<<"}\n";
    }
    
    return 0;
}