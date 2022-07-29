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


void solve()
{
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int w = s.size();
    vector<vector<int>>dp(w, vector<int>(4));
    int l = 0, u = 0;
    int mxleft = 0, mxright = 0, mxup = 0, mxdown = 0;
    for(int i = 0;i<w;++i){
        if(s[i] == 'L')l--;
        else if(s[i] == 'R') l++;
        else if(s[i] == 'U')u++;
        else  u--;
        if(l < 0){
            mxleft = max(mxleft, abs(l));
        }else if(l>=0){
            mxright = max(mxright, l);
        }

        if(u < 0){
            // moving down more
            mxdown = max(mxdown, abs(u));
        }else if(u >= 0) mxup = max(mxup, u);
        dp[i][0] = mxleft;
        dp[i][1] = mxright;
        dp[i][2] = mxup;
        dp[i][3] = mxdown;
    }   
    int i = (n+1)/2, j = (m+1)/2;
    int starti = i, startj = j;
    for(int q = 0;q<w;++q){
        int mxleft = dp[q][0], mxright = dp[q][1], mxup = dp[q][2], mxdown = dp[q][3];
        int goup = mxup+1, godown = n-mxdown;
        int goleft = mxleft+1, goright = m-mxright;
        if(s[q] == 'L'){
            j--;
            if(j < 1){
                // you want to shift starting position to the right
                if(startj < goright){
                    startj++;
                    j++;
                }else break;
            }
        }else if(s[q] == 'R'){
            j++;
            if(j > m){
                // you want to shift starting j to the left
                if(startj > goleft){
                    startj--;
                    j--;
                }else break;
            }
        }else if(s[q] == 'U'){
            i--;
            if(i < 1){
                // you want to shift starting position down 
                if(starti < godown){
                    starti++;
                    i++;
                }else break;
            }
        }else{
            i++;
            if(i > n){
                // you want to shift startign i pos up
                if(starti > goup){
                    starti--;
                    i--;
                }else break;
            }
        }
    }
    cout << starti << ' ' << startj << endl;
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