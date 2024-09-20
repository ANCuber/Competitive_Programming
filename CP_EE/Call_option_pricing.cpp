#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

long double cur, str, tmp, sum = 0;
int days, shares;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    srand(time(NULL));
    cout<<"Please input the current price of MCD:"<<endl;
    cin>>cur;
    cout<<"Please input the strike price:"<<endl;
    cin>>str;
    cout<<"Please input how many days you will be waiting:"<<endl;
    cin>>days;
    cout<<"Please input how many shares does it cover:"<<endl;
    cin>>shares;
    for (int i = 0; i < 1000; ++i) {
        tmp = cur;
        for (int j = 0; j < 86400*days; ++j) ((rand()^days^shares^i^rand())&1)?(tmp*=1.0001):(tmp*=0.9999);
        sum += max(tmp*0.0,tmp-str)*shares;
    }
    cout<<"The estimate of the price of the call option: ";
    cout<<sum/1000<<" (in total)"<<endl;
    return 0;
}
