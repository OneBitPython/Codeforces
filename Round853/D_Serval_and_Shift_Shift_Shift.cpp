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


char give(char a,char b){
    if(a==b)return '0';
    return '1';
}
void solve()
{
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    if(a==b){
        cout << 0 << endl;
        return;
    }
    vector<int>res;
    // if taking help from right, then bitshift left else bitshift right
    if(b[0]=='1'){
        if(a[0]!='1'){
            if(count(all(a),'1')==0){
                cout << -1 << endl;
                return;
            }
            for(int i = 1;i<n;++i){
                if(a[i]=='1'){
                    res.pb(i);
                    for(int j = 0;j<n;++j){
                        if(j+i >= n)break;
                        a[j] = give(a[j],a[j+i]);
                    }
                    break;
                }
            }
        }
        for(int i = 1;i<n;++i){
            if(a[i]!=b[i]){
                res.pb(-i);
                for(int j = n-1;j>=i;--j){
                    a[j] = give(a[j],a[j-i]);
                }
            }
        }
    }else if(b.back()=='1'){
        if(a.back()!='1'){
            if(count(all(a),'1')==0){
                cout << -1 << endl;
                return;
            }
            for(int i = n-2;i>=0;--i){
                if(a[i]=='1'){
                    res.pb(-(n-i-1));
                    int c = n-i-1;
                    for(int j = n-1;j>=0;--j){
                        if(j-c < 0)break;
                        a[j] = give(a[j],a[j-c]);
                    }
                    break;
                }
            }
        }
        for(int i = n-2;i>=0;--i){
            if(a[i]!=b[i]){
                int c = n-i-1;
                res.pb(c);
                for(int j = 0;j<=i;++j){
                    a[j] = give(a[j],a[j+c]);
                }
            }
        }
    }else{
        if(count(all(a),'1')==0){
            cout << -1<< endl;
            return;
        }
        if(count(all(b),'1')==0){
            cout << -1 << endl;
            return;
        }
        int st = -1;
        for(int i = 0;i<n;++i){
            if(b[i]=='1'){
                if(a[i]=='0')st = i;
                break;
            }
        }
        // what if there exists no set bit to the right of st?
        bool found = 0;
        for(int i = st+1;i<n;++i){
            found |= (a[i]=='1');
        }
        if(st!=-1 && !found){
            // we have to search to the left of it to get st set in a
            found = 0;
            int fr = 0;
            for(int i = 0;i<st;++i){
                if(a[i]=='1')fr = i;
                found|=(a[i]=='1');
            }
            if(!found){
                cout << -1 << endl;
                return;
            }
            res.pb(-(st-fr));
            for(int i = n-1;i>=0;--i){
                int c = st-fr;
                if(i-c < 0)break;
                a[i] = give(a[i],a[i-c]);
            }
        }
        if(st!=-1 && found){
            for(int i =st+1;i<n;++i){
                if(a[i]=='1'){
                    // take help from left side ie it's each value becomes a[i]^a[i+k]
                    int c = i-st;
                    res.pb(c);
                    for(int j = 0;j<n;++j){
                        if(j+c >= n)break;
                        a[j] = give(a[j], a[j+c]);
                    }
                }
                break;
            }
        }
        // a[st] = 1 but we also have to make sure that there are no values to the left and right of st
        for(int i = 0;i<n;++i){
            if(b[i]=='1'){
                st = i;
                break;
            }
        }
        if(st==-1){
            cout << -1 << endl;
            return;
        }
        for(int i = st+1;i<n;++i){
            if(a[i]!=b[i]){
                int c = i-st;
                res.pb(-c);
                // a[i] ^= a[i-c]
                for(int j =n-1;j>=0;--j){
                    if(j-c < 0)break;
                    a[j] = give(a[j], a[j-c]);
                }
            }   
        }
    }
    cout << res.size() << endl;
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