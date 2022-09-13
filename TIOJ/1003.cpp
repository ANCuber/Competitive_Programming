#include <bits/stdc++.h>
using namespace std;

int f(int);

int main() {
	int n; cin>>n;
	cout<<f(n)<<'\n';
	return 0;
}

int f(int x) {
	if (x == 0) return 1;
	return f(x-1)+x;
}
