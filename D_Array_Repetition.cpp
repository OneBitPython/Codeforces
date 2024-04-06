#include <bits/stdc++.h>
using namespace std;

#define int __int128
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.141592653589;

typedef long long ll;
std::ostream& operator << (std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value<0?-value:value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            -- d;
            *d = "0123456789"[tmp%10];
            tmp/=10;
        }while(tmp!=0);
        if(value<0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer)-d;
        if (dest.rdbuf()->sputn(d,len)!=len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

int inf = 2e18;
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
bool cmp(__int128 x, __int128 y) { return x > y; }
void solve()
{
    int n,q;
    n = read();
    q = read();
    map<int,int>pos;
    int sz = 0;
    vector<pair<int,int>>vals;
    vector<int>a;
    while(n--){
        int b,x;
        b = read();
        x = read();
        if(b==1){
            sz++;
            pos[sz] = x;
        }else{
            if(sz >= inf)continue;
            vals.pb({sz,x});
            a.pb(sz);
            sz+=(sz*x);
        }
    }
    a.pb(inf);
    while(q--){
        int k;
        k = read();
        int w= lower_bound(all(a),k)-a.begin()-1;
        for(int i = w;i>=0;--i){

            pair<int,int>x = vals[i];
            int l = x.first+1, r = x.first + (x.first * x.second);
            if(k < l)continue;
            if(r <= 0)r = inf;
            if(k >= l && k<= r){
                int times = (k-x.first)/x.first;
                k-=(times*x.first);
                while(k > x.first)k-=x.first;
            }else break;
        }
        
        cout << pos[k] << ' ';
    }
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
    T = read();
    for(int i = 1;i<=T;++i)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
}