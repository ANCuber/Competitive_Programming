#include <bits/stdc++.h>
using namespace std;

vector <int> graph;

void initialize(int n) {
    graph.resize(n);
    for (auto i : graph) graph[i] = 0;
}

int hasEdge(int a, int b) {
    if (++graph[max(a,b)] == max(a,b)) return 1;
    return 0;
}