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


int add(int x, int mn, int mxp, int sum){
    // try to add x
    int big = 0;
    sum+=x;
    if(sum < 0){
        sum-=mxp;
    }else if(sum==0){
        sum = max(abs(mn), mxp);
    }else sum-=mn;
    return sum;
}
void solve()
{
    int n;
    cin >> n;
    vector<int>pos,neg;
    bool ok = 0;
    for(int i = 0;i<n;++i){
        int v;
        cin >> v;
        if(v!=0)ok = 1;
        if(v > 0)pos.pb(v);
        else neg.pb(v);
    }
    if(!ok){
        cout << "No" << endl;
        return;
    }
    sort(all(pos));
    sort(all(neg));
    reverse(all(neg));
    int p1 = 0, p2 = 0;
    int sum = 0; // prefix sum
    vector<int>res;
    int mx = *max_element(all(pos))-*min_element(all(neg));
    int mxp = 0, mnn = 0; // mxp -> mx prefix sum, mnn - > min prefix sum
    bool choose = 1;
    for(int i= 0;i<n;++i){
        bool done = 0;
        if(choose){
            if(p1 <(int)(pos.size())){
                int ne = add(pos[p1],mnn,mxp,sum);
                if(abs(ne) < mx){
                    res.pb(pos[p1]);
                    sum+=pos[p1];
                    p1++;
                    mnn = min(mnn, sum);
                    mxp = max(mxp, sum);
                    done = 1;
                }
            }
            if(!done){
                int ne = add(neg[p2],mnn,mxp,sum);
                if(abs(ne) < mx){
                    res.pb(neg[p2]);
                    sum+=neg[p2];
                    p2++;
                    mnn = min(mnn, sum);
                    mxp = max(mxp, sum);
                    done = 1;
                }
                choose = 0;
            }
        }else{
            if(p2 < (int)(neg.size())){
                int ne = add(neg[p2],mnn,mxp,sum);
                if(abs(ne) < mx){
                    res.pb(neg[p2]);
                    sum+=neg[p2];
                    p2++;
                    mnn = min(mnn, sum);
                    mxp = max(mxp, sum);
                    done = 1;
                }
            }
            if(!done){
                int ne = add(pos[p1],mnn,mxp,sum);
                if(abs(ne) < mx){
                    res.pb(pos[p1]);
                    sum+=pos[p1];
                    p1++;
                    mnn = min(mnn, sum);
                    mxp = max(mxp, sum);
                    done = 1;
                }
                choose = 1;
            }
        }
        if(!done){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    for(auto x : res)cout << x << ' ';
    cout << endl;
    
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}