#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

string base[30] = {" ","un","deux","trois","quatre","cinq","six","sept","huit","neuf","dix","onze","douze"
,"treize","quatorze","quinze","seize"};
string two[15] = {" ","dix","vingt","trente","quarante","cinquante","soixante"};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    if (n <= 16) {
        cout<<base[n];
    } else if (n <= 19) {
        cout<<base[10]<<'-'<<base[n%10];
    } else if (n <= 69) {
        if (n%10 == 0) {
            cout<<two[n/10];  
        } else if (n%10 == 1) {
            cout<<two[n/10]<<"-et-"<<base[1];
        } else {
            cout<<two[n/10]<<'-'<<base[n%10];
        }
    } else if(n <= 76) {
        if (n == 71) cout<<"soixante-et-onze";
        else cout<<two[6]<<'-'<<base[n-60];
    } else if (n <= 79) {
        cout<<two[6]<<'-'<<base[10]<<'-'<<base[n%10];
    } else if (n == 80) {
        cout<<"quatre-vingts";
    } else if (n <= 96) {
        cout<<"quatre-vingt-"<<base[n-80];
    } else {
        cout<<"quatre-vingt-"<<base[10]<<'-'<<base[n%10];
    }
    cout<<endl;
    return 0;
}
