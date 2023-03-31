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


string give(int x){
    stringstream ss;
    ss << x;
    string s;
    ss >> s;
    return s;
}
void solve()
{
    int l,r;
    cin >> l >> r;
    string s = give(l), t = give(r);
    if(t.size() > s.size()){
        for(int i = 0;i<s.size();++i)cout << "9";
        cout << endl;
        return;
    }
    if(l==r){
        cout << l << endl;
        return;
    }
    int start = 0;
    for(int i = 0;i<s.size();++i){
        if(s[i]!=t[i]){
            start = i;
            break;
        }
    }
    string res;
    int mn = 1e18;
    if((t[start]-'0') - (s[start]-'0')>=2){
        for(int a = s[start]-'0'+1;a<t[start]-'0';++a){
            for(int b = 0;b<=9;++b){
                string get;
                for(int i = 0;i<start;++i)get+=s[i];
                get+=(a+'0');
                while(get.size() < s.size())get+=(b+'0');
                int ans = (*max_element(all(get))-'0')-(*min_element(all(get))-'0');
                if(ans < mn){
                    mn = ans;
                    res = get;
                }
            }
        }
    }
    for(int i = start+1;i<(int)(s.size());++i){
        // follow l from [0,i-1] and then you can choose any digit >s[i] in position i and then choose any digit for other positions
        for(int a = (s[i]-'0')+1;a<=9;++a){
            for(int b = 0;b<=9;++b){
                string get;
                for(int j = 0;j<=i-1;++j)get+=s[j];
                get+=(a+'0');
                while(get.size() < s.size())get+=(b+'0');
                int ans = (*max_element(all(get))-'0')-(*min_element(all(get))-'0');
                if(ans < mn){
                    mn = ans;
                    res = get;
                }
            }
        }
    }
    for(int i = start+1;i<(int)(s.size());++i){
        // follow r from [0,i-1] and then you can choose any digit <t[i] in position i and then choose any digit for other positions
        for(int a = (t[i]-'0')-1;a>=0;--a){
            for(int b = 0;b<=9;++b){
                string get;
                for(int j = 0;j<=i-1;++j)get+=t[j];
                get+=(a+'0');
                while(get.size() < s.size())get+=(b+'0');
                int ans = (*max_element(all(get))-'0')-(*min_element(all(get))-'0');
                if(ans < mn){
                    mn = ans;
                    res = get;
                }
            }
        }
    }
    for(auto x : {l,r}){
        string s = give(x);
        int val = (*max_element(all(s))-'0') - (*min_element(all(s))-'0');
        if(val < mn){
            mn = val;
            res = s;
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
    cin >> T;
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}