#include <bits/stdc++.h>
using namespace std;

struct mahjong{
	int num;
	char kind;
	bool operator<(mahjong b) {
		if (kind != b.kind) return kind < b.kind;
		else return num < b.num;
	}
};

mahjong makemaj(string a) {
	mahjong b;
	b.num = a[0]-'0';
	b.kind = a[1];
	return b;
}

vector <struct mahjong> mj;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin>>t;
	for (int z = 0; z < t; z++) {
		mj.clear();
		for (int i = 0; i < 13; i++) {
			string x; cin>>x;
			mj.push_back(makemaj(x));
		}
		sort(mj.begin(), mj.end());
		int q; cin>>q;
		for (int i = 0; i < q; i++) {
			
		}
		for (int i = 0; i < mj.size(); i++) cout<<mj[i].num;
		cout<<'\n';
		for (int i = 0; i < mj.size(); i++) cout<<mj[i].kind;
		cout<<'\n';
		
	}
	return 0;
}


