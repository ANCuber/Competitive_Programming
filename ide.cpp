#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    srand(time(NULL));
    vector<int> v;
    while(cin>>n && n) {
        v.push_back(n);
    }
    int rd = (rand()*rand())%v.size();
    cout<<v[rd]<<endl;
    return 0;
}
