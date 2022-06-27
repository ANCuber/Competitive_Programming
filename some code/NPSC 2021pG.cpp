#include <iostream>
#include <algorithm>

using namespace std;

int main () {
	vector<int> list;
	long long num;
	cin >> num;
	long long temp;
	for (int i = 0; i < num; i++) {
		cin >> temp;
		list.push_back(temp);
	} 
	sort(list.begin(), list.end());
	long long sum = 0;
	for (int i = 0; i < num / 2; i++) {
		sum += list[i];
	}
	cout<<sum<<"\n";
	return 0;
} 
