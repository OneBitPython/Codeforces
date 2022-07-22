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


bool RBS(vector<char>a){
    stack<char>st;
    for(int i = 0;i<a.size();++i){
        if(a[i] == '(')st.push('(');
        else{
            if(st.empty())return 0;
            st.pop();
        }
    }
    return 1;
}

void solve()
{
    string w;
    cin >>w;

    vector<char>s(all(w));
    vector<char>a = s;

    int n = s.size();


    int extra_open = n/2-(count(all(s), '('));
    int extra_close = n/2-(count(all(s), ')'));
    int filledopen = 0;
    vector<int>openbrackets;
    for(int i = 0;i<n;++i){
        if(s[i] == '?'){
            if(filledopen < extra_open){
                filledopen++;
                s[i] = '(';
                openbrackets.pb(i);
            }else{
                break;
            }
        }
    }
    vector<int>closingbrackets;
    for(int i = 0;i<n;++i){
        if(s[i] == '?'){
            s[i] = ')';
            closingbrackets.pb(i);
        }
    }
    int t = closingbrackets.size(), f = openbrackets.size();
    if(!t || !f){
        cout << "YES" << endl;
        return;
    }

    int idx1 = openbrackets.back(), idx2 = closingbrackets.front();
    bool ok = RBS(s);
    swap(s[idx1], s[idx2]);
    if(RBS(s) && ok)cout << "NO" << endl;
    else cout << "YES" << endl;
    
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