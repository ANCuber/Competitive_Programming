int n;
const int MOD = 1e9+7;
struct matrix{
    vector<vector<int> > arr;
    void init(int v){
        arr.resize(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr.push_back((i==j)?v:0); 
            }
        }
    }
    void print(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) cerr<<arr[i][j]<<" ";
            cerr<<"\n";
        }
    }
};

matrix operator*(matrix &a,matrix &b){
    matrix r;
    r.init(0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++) {
                r.arr[i][j]=(r.arr[i][j]+(1LL*a.arr[i][k]*b.arr[k][j]%MOD))%MOD;
        }
    }
    return r; 
}

matrix pow(matrix a,int p){
    matrix r;
    r.init(1);
    while(p){
        if(p&1) r = r*a;
        a = a*a; 
    }
    return r;
}

