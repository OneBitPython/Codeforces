#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "LINE(" << __LINE__ << ") -> " <<"[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif


vector<vector<char>>a;
vector<pair<int,int>>p;
vector<vector<int>>res;
int n,m;
int give_cnt_set(){
    int cnt = 0;
    for(auto x : p){
        if(a[x.first][x.second] == '1')cnt++;
    }
    return cnt;
}

void update(vector<int>&add){

    for(int i = 0;i<6;i+=2){
        char val = a[add[i]][add[i+1]];
        a[add[i]][add[i+1]] = (val=='0'?'1':'0');
    }
}

void process4(){
    // convert any 3 set bits to not set bits
    vector<int>add;
    for(int i = 0;i<3;++i){
        add.pb(p[i].first);
        add.pb(p[i].second);
    }
    res.pb(add);
    update(add);
}

void process3(){
    // take all the three bits
    vector<int>add;
    for(int i = 0;i<4;++i){
        if(a[p[i].first][p[i].second] == '1'){
            add.pb(p[i].first);
            add.pb(p[i].second);
        }
    }
    res.pb(add);
    update(add);
}

void process2(){
    vector<int>add;
    for(int i = 0;i<4;++i){
        if(a[p[i].first][p[i].second] == '0'){
            add.pb(p[i].first);
            add.pb(p[i].second);
        }
    }
    for(int i = 0;i<4;++i){
        if(a[p[i].first][p[i].second] == '1'){
            add.pb(p[i].first);
            add.pb(p[i].second);
            break;
        }
    }
    res.pb(add);
    update(add);
}

void process1(){
    vector<int>add;
    for(int i = 0;i<4;++i){
        if(a[p[i].first][p[i].second] == '1'){
            add.pb(p[i].first);
            add.pb(p[i].second);
            break;
        }
    }
    int taken = 0;
    for(int i = 0;i<4;++i){
        if(a[p[i].first][p[i].second] == '0' && taken < 2){
            taken++;
            add.pb(p[i].first);
            add.pb(p[i].second);
        }
    }
    res.pb(add);
    update(add);
}

void process(){
    int cnt = give_cnt_set();
    if(cnt == 4){
        process4();
    }
    cnt = give_cnt_set();
    if(cnt == 1){
        process1();
    }
    cnt = give_cnt_set();
    if(cnt == 2){
        process2();
    }
    cnt = give_cnt_set();
    if(cnt == 3){
        process3();
    }
}

void solve()
{
    cin >> n >> m;
    a = vector<vector<char>>(n, vector<char>(m));
    auto w = a;
    res.clear();
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j)cin >> a[i][j];
    }
    for(int i = 0;i<n-1;i+=2){
        for(int j = 0;j<m-1;j+=2){
            p.clear();
            p.pb({i, j});
            p.pb({i+1, j});
            p.pb({i, j+1});
            p.pb({i+1, j+1});
            process();
        }
    }
    if(m%2){
        for(int i = 0;i<n-1;++i){
            int j = m-2;
            p.clear();
            p.pb({i, j});
            p.pb({i+1, j});
            p.pb({i, j+1});
            p.pb({i+1, j+1});
            process();
        }
    }
    if(n%2){
        for(int j = 0;j<m-1;++j){
            int i = n-2;
            p.clear();
            p.pb({i, j});
            p.pb({i+1, j});
            p.pb({i, j+1});
            p.pb({i+1, j+1});
            process();
        }
    }
    cout<< res.size() << endl;
    for(auto x : res){
        for(auto y : x){
            cout << y+1 <<  ' ';
        }
        cout << endl;
    }
    
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}