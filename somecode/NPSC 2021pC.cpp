#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> list;

bool test(vector<bool>);

int main() {
    int length;
    string input;
    while (cin >> length >> input) {
        list.clear();
        for (int i = 0; i < length; i++) list.push_back(input[i] - '0');
        bool ans = 0;
        for (int i = 0; i < 2; i++) {
            if (list[0] == 0) {
                list[0] = 1;
                list[1] = !list[1];
                ans |= test(list);
                list[2] = !list[2];
                ans |= test(list);
            }
            ans |= test(list);
            reverse(list.begin(), list.end());
        }

        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}
bool test(vector<bool> input) {
    for (int i = 1; i < input.size() - 1; i++) {
        if (!input[i]) {
            input[i] = !input[i];
            input[i + 1] = !input[i + 1]; 
            input[i + 2] = !input[i + 2]; 
        }
    }
    return *input.rbegin();
}