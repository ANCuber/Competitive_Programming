#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<string> code;
    vector<int> indent;
    string input;
    do {
        getline(cin, input);
        int cnt = 0;
        while (input[cnt] == ' ') cnt++;
        indent.pb(cnt);
        code.pb(input);
    } while (input != "end");
    
    int N = code.size() - 1;
    vector<int> type(N);
    vector< vector<int> > list(N);
    vector< vector<int> > indentList(400);
    auto backup = indentList;

    bool flag = 0;
    for (int i = 0; i < N; i++) {
        if (indent[i] < indent[i + 1] && indent[i] + 2 != indent[i + 1]) flag = 1;
    }

    if (flag) {
        cout << "ERR!";
        return 0;
    }

    int last = -1;
    for (int i = 0; i < N; i++) {
        if (code[i] == "emptyline" && code[i + 1] != "emptyline") {
            type[i] = 1;
            list[i].pb(i + 2);
            last = i;
            indentList = backup;
            continue;
        }
        if (last >= 0 && code[i + 1] == "emptyline" || code[i + 1] == "end" ) {
            list[last].pb(i + 1);
            last = -1;
        }
        string s;
        for (int j = indent[i]; j < code[i].size(); j++) s += code[i][j];
        if (s == "safe") {
            type[i] = 2;
            list[i] = indentList[indent[i]];
            indentList[indent[i]].resize(0);
            continue;
        }

        indentList[indent[i]].pb(i + 1);

    }


    for (int i = 0; i < N; i++) {
        if (type[i] == 0) cout << code[i] << '\n';
        if (type[i] == 1) {
            cout << "//Describe(" << list[i][0] << ',' << list[i][1] << ")\n";
        }
        if (type[i] == 2) {
            for (int j = 0; j < indent[i]; j++) cout << ' ';
            cout << "!!!Analyze(";
            for (auto& n: list[i]) {
                cout << "ln" << n;
                if (&n != &list[i].back()) cout << ",";
            }
            cout << ')';
            cout << '\n';
        }
    }

    return 0;
}
