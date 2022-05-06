#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

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

void print(){cerr << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cerr << one << " ";
    print(rest...);
}


int sum() { return 0; }
template<typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

string bin(long n){
    long i;
    string val = "0";
    for (i = 1 << 30; i > 0; i = i / 2)
    {
      if((n & i) != 0)
      {
        val+="1";
      }
      else
      {
        val+="0";
      }
    }
    while(val.front()=='0'){
        val.erase(0,1);
    }
    return val;
}




void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char,int>cnt;// operations done by character c
    for(int i = 0;i<n;++i){
        // set s[i] to least possible
        while(cnt[s[i]]){
            int c = cnt[s[i]];
            // reduce character s[i] by c
            c%=26;
            int j = s[i];
            while(c > 0){
                c--;
                if(j == 97)j = 97+25;
                else{
                    j--;
                }
            }
            char w =j;
            s[i] = w;
        }
        if(k>0){
            char x = s[i];
            
            int got = 97;
            int  m = 1e9;
            int tmp = k;
            for(int j = x;j>=97;--j){
                if(cnt[j]!=0){
                    if(tmp<=0)break;
                    int reached = j;
                    while(cnt[reached])reached-=cnt[reached];
                    if(reached < m){
                        m = reached;
                        got = j;
                    }
                }
                tmp--;
            }
            int op = 0;
            for(int j = x-1;j>=got;--j){
                op++;
            }
            op = min(op, k);
            cnt[x] += op;
            op--;
            for(int j = x-1;j>=got;--j){
                char v =j;
                if(k > 0){
                    
                    s[i] = j;
                    cnt[j] += op;
                    op--;
                    k--;
                }
            }
            while(cnt[s[i]]!=0){
                int c = cnt[s[i]];
                c%=26;
                int j = s[i];

                while(c > 0){
                    c--;
                    if(j == 97){
                        j = 97+25;
                    }
                    else{
                        j--;
                    }
                }
                char w =j;
                s[i] = w;
            }

        }
    }
    cout << s << endl;
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
        solve();
    }
}