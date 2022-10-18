#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

//left, right, straight

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string x;
    while(cin>>x) {
        for (int i = 0; i < 4; ++i) {
            if (i) cout<<", ";
            int flag = 0;
            if (x[i] == 'a') {
                if(x[(i+3)%4] != 'a') cout<<"A",flag = 1;
                if(x[(i+1)%4] != 'a') cout<<"B",flag = 1;
                if(x[(i+2)%4] != 'a') cout<<"C",flag = 1;
            } else if (x[i] == 'c') { 
                if(x[(i+3)%4] != 'a') cout<<"A",flag = 1;
                if(x[(i+1)%4] != 'a') cout<<"B",flag = 1;
                if(x[(i+2)%4] != 'a') cout<<"C",flag = 1;
            } else {
                cout<<'X';
                flag = 1;
            }
            if (!flag) cout<<'Y';
        }
        cout<<endl;
    }
    return 0;
}
