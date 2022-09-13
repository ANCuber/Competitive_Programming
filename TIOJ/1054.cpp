#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

string arr[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int main() {
    string day; cin>>day;
    int n; cin>>n;
    int today;
    for (int i = 0; i < 7; ++i) {
        if (arr[i] == day) {
            today = i;
            break;
        }
    }
    cout<<arr[(today+n)%7]<<endl;
    return 0;
}