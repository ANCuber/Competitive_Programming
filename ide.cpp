struct Query {int id, k;};

int ans[N];//the answer of the i-th query
int check(int x);//the number of numbers <= x

void solve(int l, int r, vector<Query> q) {
    if (l == r) {
        for (auto i : q) ans[i.id] = l;
        return;
    }
    int mid = (l+r)>>1;
    int c = check(mid);
    vector<Query> ql, qr;//part
    for (auto i : q) {
        if (i.k <= c) ql.push_back(i);
        else qr.push_back(i);
    }
    solve(l,mid,ql), solve(mid+1,r,qr);
    return;
}

