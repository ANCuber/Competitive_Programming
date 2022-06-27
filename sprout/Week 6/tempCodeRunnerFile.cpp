vector <vector<int> > graph;

int GetVal (int p, int q) {
    return graph[p-1][q-1];
}

void Report(int x) {
    cout<<x<<endl;
}