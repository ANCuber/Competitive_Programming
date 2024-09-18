#include <bits/stdc++.h>

#pragma GCC optimize("O3,unroll-loops")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define F first
#define S second
#define int long long
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// debugger
// ===================================
bool debug_mode=true;
template<typename T> void _do(T x){cerr<<x<<"\n";}
template<typename T, typename ...U> void _do(T x, U ...y){cerr << x << ", "; _do(y...);}
#define dbg(...) cerr << #__VA_ARGS__ << " = "; _do(__VA_ARGS__);
template<typename T>void debug(const T &v,int h,int w,string sv=" "){for(int i=0;i<h;i++){cerr<<v[i][0];for(int j=1;j<w;j++)cerr<<sv<<v[i][j];cerr<<endl;}};
template<typename T>void debug(const T &v,int n,string sv=" "){if(n!=0)cerr<<v[0];for(int i=1;i<n;i++)cerr<<sv<<v[i];cerr<<endl;};
template<typename T>void debug(const vector<T>&v){debug(v,v.size());}
template<typename T>void debug(const vector<vector<T>>&v){for(auto &vv:v)debug(vv,vv.size());}
template<typename T>void debug(stack<T> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(queue<T> st){while(!st.empty()){cerr<<st.front()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(deque<T> st){while(!st.empty()){cerr<<st.front()<<" ";st.pop_front();}cerr<<endl;}
template<typename T>void debug(priority_queue<T> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(priority_queue<T, vector<int>, greater<int>> st){while(!st.empty()){cerr<<st.top()<<" ";st.pop();}cerr<<endl;}
template<typename T>void debug(const set<T>&v){for(auto z:v)cerr<<z<<" ";cerr<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cerr<<z<<" ";cerr<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cerr<<"["<<z.first<<"]="<<z.second<<", ";cerr<<endl;}
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cerr<<z<<" ";cerr<<endl;}
// ===================================

// declare
const int MAX_N = 500+5;
const int MAX_D = 30+5;
const int INF = 2e9;
const int MOD = 1e9+7;
const double EPS = 1e-6;

int N, K, D, w, v;
vector<pair<int, int>> item;
int pre[MAX_D][MAX_D];

void init(){
    for (int i=0 ; i<MAX_D ; i++){
        for (int j=0 ; j<MAX_D ; j++){
            pre[i][j] = (i*j)%D;
        }
    }
}

void Max(int &A, int B){
    A = max(A, B);
}

void solve1(){

    // input
    cin >> N >> K >> D;
    //assert(N<=500);
    if (N>500) return;
    init();
    for (int i=0 ; i<N ; i++){
        cin >> w >> v;
        item.push_back({w, v});
    }

    // process
    // dp[i][j][k] = 對前 i 個物品，選到 j 個，權重是餘數 k 的最大價值
    vector<vector<vector<int>>> dp;
    dp.resize(2, vector<vector<int>>(K+10, vector<int>(D+10, -INF)));
    dp[0][0][0] = 0;
    for (int i=0 ; i<N ; i++){
        dp[1] = dp[0];

        for (int j=0 ; j<K ; j++){
            for (int k=0 ; k<D ; k++){
                //Max(dp[1][0][k],dp[0][0][k]);
                if (dp[0][j][k]==-INF) continue;

                // 不拿
                Max(dp[1][j+1][k], dp[0][j+1][k]);

                // 拿
                if (j==0){
                    Max(dp[1][j+1][item[i].first],item[i].second);
                    //Max(dp[1][j+1][item[i].first], dp[0][j][k]+item[i].second);
                }else{
                    Max(dp[1][j+1][pre[k][item[i].first]], dp[0][j][k]+item[i].second);
                }
            }
        }


        swap(dp[0], dp[1]);
        // for (int i=0 ; i<=K ; i++){
        //     for (int j=0 ; j<D ; j++){
        //         if (dp[0][i][j]==-INF){
        //             cout << "X ";
        //         }else{
        //             cout << dp[0][i][j] << " ";
        //         }
        //     }
        // }
        // cout << "\n";
        // cout << "\n";
    }

    // output
    for (int i=0 ; i<D ; i++){
        if (i) cout<<' ';
        if (dp[0][K][i]==-INF){
            cout << "0";
        }else{
            cout << dp[0][K][i];
        }
    }
    cout << "\n";
    

    return;
}

void solve2(){

    // cin >> N >> K >> D;
    // for (int i=0 ; i<N ; i++){
    //     cin >> w >> v;
    //     item.push_back({w, v});
    // }

    vector<int> ans(D);
    for (int i=0 ; i<(1<<N) ; i++){
        int take = 0;
        int total = -1;
        int value = 0;

        for (int j=0 ; j<N ; j++){
            if ((i>>j)&1){
                take++;
                if (total==-1){
                    total = item[j].first;
                }else{
                    total = (total*item[j].first)%D;
                }
                value += item[j].second;
            }
        }


        if (take==K){
            Max(ans[total], value);
        }
    }

    // output
    for (int i=0 ; i<D ; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";
}

void gen(){
    srand(time(NULL));
    cerr << 3 << " " << 3 << " " << 21 << "\n";
    for (int i=0 ; i<3 ; i++){
        cerr << rand()%21 << " " << rand()%21+1 << "\n";
    }
}

signed main(void){
    fastio;
    
    int t=1;
    // gen();
    // return 0;
    while (t--){
        solve1();
        // solve2();
    }
    return 0;
}
