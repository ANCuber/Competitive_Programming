#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl '\n'
#define pii pair<int,int>
 
int main() {
	ll n; cin>>n;
	cout<<n;
	while(n!=1) {
		if (n&1) n = n*3+1;
		else n>>=1;
		cout<<' '<<n;
	}
	cout<<endl;
	return 0;
}
