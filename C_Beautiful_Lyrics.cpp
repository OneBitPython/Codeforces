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


void solve()
{
    int n;
    cin >> n;
    vector<string>a(n);
    for(string &u : a)cin >> u;
    // fidn the number of words which have same number of vowels
    map<int,vector<string>>mp;
    map<pair<char,int>,vector<string>>mp2;
    set<char>vowels = {'a', 'e', 'i', 'o', 'u'};
    map<string,int>pres;
    for(int i = 0;i<n;++i){
        int cnt = 0;
        pres[a[i]]++;
        for(auto x : a[i]){
            if(vowels.count(x))cnt++;
        }
        for(int j = (int)(a[i].size())-1;j>=0;--j){
            if(vowels.count(a[i][j])){
                mp2[{a[i][j], cnt}].pb(a[i]);
                break;
            }
        }
        mp[cnt].pb(a[i]);
    }
    vector<pair<string,string>>c,d;
    map<string,int>taken;
    for(auto x : mp2){
        vector<string>untaken;
        for(int i = 0;i<(int)(x.second.size());i++){
            if(taken[x.second[i]] >= pres[x.second[i]])continue;
            untaken.pb(x.second[i]);
        }
        for(int i = 0;i<(int)(untaken.size());i+=2){
            if((i+1) >= (int)(untaken.size()))break;
            taken[untaken[i]]++;
            taken[untaken[i + 1]]++;
            d.pb({untaken[i],untaken[i+1]});
        }
    }
    for(auto x : mp){
        vector<string>untaken;
        for(int i = 0;i<(int)(x.second.size());i++){
            if(taken[x.second[i]] >= pres[x.second[i]])continue;
            untaken.pb(x.second[i]);
        }
        for(int i = 0;i<(int)(untaken.size());i+=2){
            if(i+1 >= (int)(untaken.size()))break;
            taken[untaken[i]]++;
            taken[untaken[i+1]]++;
            c.pb({untaken[i],untaken[i+1]});
        }
    }
    
    vector<vector<string>>res;
    vector<pair<string,string>>comb;
    for(auto x : c)comb.pb(x);
    for(auto x : d)comb.pb(x);



    int pos = 0, pos2 = (int)(comb.size()) - 1;
    while(pos < pos2){
        if(pos2 >= c.size()){
            res.pb({comb[pos].first, comb[pos2].first, comb[pos].second, comb[pos2].second});
        }
        pos++;
        pos2--;
    }
    cout<< res.size() << endl;
    for(auto x : res){
        cout << x[0] << ' ' << x[1] << endl;
        cout << x[2] << ' ' << x[3] << endl;
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
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}