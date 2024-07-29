#include<bits/stdc++.h>
using namespace std;

int sum_of_digits(int x){
	int ans = 0;
	while(x){
		ans += x%10;
		x/=10;
	}
	return ans;
}

struct cmp{
	bool operator()(int a, int b){
		return sum_of_digits(a) < sum_of_digits(b);
	}
};

set<int, cmp> s;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	s.insert(56);
	s.insert(11);
	s.insert(7);
	for(auto i:s) cout << i << '\n';
}
