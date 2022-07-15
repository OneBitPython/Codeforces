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

bool check(vector<pair<int,int>>&a){
    set<int>st;
    for(int i = 0;i<a.size();++i){
        if(st.count(a[i].first) == 1)return 0;
        st.insert(a[i].first);
        if(st.count(a[i].second) == 1)return 0;
        st.insert(a[i].second);
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int,int>>p(n);
    for(int i = 0;i<n;++i)cin >> p[i].first >> p[i].second;
    vector<pair<int,int>>a,b;
    vector<pair<int,int>>add;
    vector<vector<pair<int,int>>>vals(n+5);
    map<pair<int,int>,int>pres;
    for(int i = 0;i<n;++i){
        vals[p[i].first].pb(p[i]);
        vals[p[i].second].pb(p[i]);
        pres[p[i]]++;
        if(vals[p[i].first].size() > 2 || vals[p[i].second].size() > 2 || p[i].first == p[i].second){
            cout << "NO" << endl;
            return;
        }
    }

    add.pb(p[0]);
    map<pair<int,int>,int>taken; 
    taken[p[0]] = 1;
    a.pb(p[0]);
    bool m = 0; 

    multiset<pair<int,int>>mt;
    for(int i = 1;i<n;++i){
        mt.insert(p[i]);
    }
    while(!mt.empty()){
        vector<pair<int,int>>new_add;
        for(auto x : add){
            // if x.first ==1, then the other p[i] with 1 as first element or second elemnt should be in the other group
            int i = x.first, j = x.second;
            for(auto y : vals[i]){
                if(taken[y] < pres[y]){
                    taken[y]++;
                    if(m)a.pb(y);
                    else b.pb(y);
                    new_add.pb(y);
                    mt.erase(find(all(mt), y));
                }
            }
            for(auto y : vals[j]){
                if(taken[y] < pres[y]){
                    taken[y]++;
                    if(m)a.pb(y);
                    else b.pb(y);
                    new_add.pb(y);
                    mt.erase(find(all(mt), y));
                }
            }
        }
        add = new_add;
        if(add.empty() && !mt.empty()){
            add.pb(*mt.begin());
            a.pb(*mt.begin());
            taken[*mt.begin()]++;
            mt.erase(mt.begin());
        }
        m = !m;
    }
    if(check(a) && (check(b)))cout << "YES" << endl;
    else cout << "NO" << endl;
}   
// 1,4 2,3 4,5 3,5
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