#include <bits/stdc++.h>
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 0; i < 15; ++i) {
        cout<<"\\\\log_{";
        cout<<rand()%11;
        cout<<"} ";
        cout<<endl;
    }
    return 0;
}