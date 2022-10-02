#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;


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


vector<int>id, sz;
int root(int x){
    if(x==id[x])return x;
    return id[x] = root(id[x]);
}

void merge(int u, int v){
    u = root(u);
    v = root(v);
    if(u==v)return;
    if(sz[v] > sz[u])swap(u,v);
    id[v] = u;
    sz[u]+=sz[v];

}

bool same(int u, int v){
    return root(u) == root(v);
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,char>mp;
    set<char>st;
    for(char i = 'a';i<='z';++i)st.insert(i);
    
    id.clear();
    sz.clear();
    id.resize(26);
    sz.resize(26, 1);
    for(int i = 0;i<26;++i)id[i] = i;

    string res;
    vector<int>taken(26),paired(26);
    for(int i= 0;i<n;++i){
        if(paired[s[i]-'a']){
            res+=mp[s[i]];
            continue;
        }
        bool ok = 0;
        for(auto x : st){
            if(!same(x-'a',s[i]-'a')){
                mp[s[i]] = x;
                taken[x-'a'] = 1;
                paired[s[i]-'a'] = 1;
                merge(x-'a', s[i]-'a');
                res+=x;
                ok = 1;
                break;
            }
        }
        if(!ok){
            for(int j = 0;j<26;++j){
                if(taken[j]==0){
                    taken[j] = 1;
                    paired[s[i]-'a'] = 1;
                    merge(j,s[i]-'a');
                    char w = j+97;
                    res+=w;
                    mp[s[i]] = w;
                    break;
                }
            }
        }
        st.erase(res.back());
    }
    cout << res << endl;
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