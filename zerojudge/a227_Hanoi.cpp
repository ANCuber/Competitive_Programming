#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        cout<<"Move ring "<<n<<" from "<<a<<" to "<<c<<"\n";
        return;
    }
    hanoi(n-1,a,c,b);
    cout<<"Move ring "<<n<<" from "<<a<<" to "<<c<<"\n";
    hanoi(n-1,b,a,c);
}

int main() {
    int n;
    while(cin>>n) {
        hanoi(n,'A','B','C');
        cout<<endl;
    }
    return 0;
}