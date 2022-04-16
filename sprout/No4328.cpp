#include <bits/stdc++.h>
using namespace std;

int walkOnMyOwnPath(int path[], int pos[], int size, int time){
    vector <unordered_set<int> > population(100000);
    int t = 0;
    for (int i = 0; i < size; ++i) {
        population[pos[i]].insert(i);
    }
    while(t <= time) {
        for (int i = 0; i < size; ++i) {
            int before = pos[i];
            int destination = path[before];
            pos[i] = destination;
        }
        t++;
    }
    return -1;
}

int main() {
    int n, m, t;
    int path[100000] = {};
    int pos[10] = {};
    cin >> n >> m >> t;

    for (int i = 0; i < n; i++) {
        cin >> path[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> pos[i];
    }

    int isCollide = walkOnMyOwnPath(path, pos, m, t);
    if (isCollide == -1) {
        cout << "Fine :)" << endl;
    }
    else {
        cout << "Fine QQ " << isCollide << endl;
    }
    return 0;
}