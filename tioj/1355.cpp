#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int ctrl = 1;

void rev(int s, int mid, int d, int a) {
   if (a == 1) {
        cout<<'#'<<ctrl++<<" : move the dish from #";
        cout<<s<<" to #"<<d;
        cout<<endl;
   } else {
        rev(s,d,mid,a-1);
        rev(s,mid,d,1);
        rev(mid,s,d,a-1);
   }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    rev(1,2,3,n);
    return 0;
}
