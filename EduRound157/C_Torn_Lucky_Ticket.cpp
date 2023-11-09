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

int ss(const string &s){
    int sum = 0;
    for(auto x : s)sum+=(x-'0');
    return sum;
}

void solve()
{
    int n;
    cin >> n;
    vector<string>a(n+1);
    for(int i = 1;i<=n;++i)cin >> a[i];
    sort(all(a), [&](auto one, auto two){
        if(one.size()==two.size())return false;
        return one.size() < two.size();
    });
    vector<vector<vector<int>>>dpp(6,vector<vector<int>>(6,vector<int>(50))); 
    // dpp[i][j][k] number of string of length i with sum(string) - 2*sum(prefix of length j ) = k 
    for(int i = 1;i<=n;++i){
        int l = a[i].size();
        int sum = 0;
        for(auto x : a[i])sum+=(x-'0');
        dpp[l][0][sum]++;
        for(int j = 0;j<l;++j){
            sum-=(2*(a[i][j]-'0'));
            if(sum<0)continue;
            dpp[l][j+1][sum]++;
        }
    }
    int res = 0;
    for(int k = 1;k<=n;++k){
        int i = a[k].size();
        for(int j = 1;j<=5;++j){
            if((i+j)%2)continue;
            // first string of length i, second of length j
            if(i <= j){
                res+=dpp[j][((i+j)/2) - i][ss(a[k])];
            }else{
                int rem = i-((i+j)/2);
                int sum = ss(a[k]);

                for(int w = 1;w<=rem;++w)sum-=(2*(a[k][i-w]-'0'));

                if(sum < 0)continue;
                res+=dpp[j][0][sum];
            }

        }
    }
    cout << res << endl;
}   

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    // #endif

    int T=1;
    // cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}