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
    string s;
    cin >> s;
    s = "0"+s;

    /*
    at any instance, you have three options - 
    * don't do anything (if s is not a palindrome)
    * change a character i so that  s[i] = s[n-i+1]
    * change a character i so that s[i] != s[n-i+1]
   */
    queue<int>diff,same;
    for(int i = 1;i<=(n/2);++i){
        if(s[i]!=s[n-i+1]){
            if(s[i]=='0')diff.push(i);
            else diff.push(n-i+1);
        }else{
            if(s[i] == '0')same.push(i);
        }
    }
    int s1 = 0, s2 = 0;
    int turn = 1, rev = -1;
    int curr = 0;
    while(1){
        if(same.empty() && diff.empty())break;
        curr++;
        if(!diff.empty()){
            // current player can reverse if valid
            if(rev!=(curr-1)){
                rev = curr;
            }else{
                if(turn==1)s1++;
                else s2++;
                s[diff.front()] = '1';
                diff.pop();
            }
        }else{
            // it is a palindrome rn so the player has to use an operation
            // he could do an operation on the  middle character if available so that it remains a palindrome
            if(n%2 && s[(n+1)/2]=='0'){
                if(turn==1)s1++;
                else s2++;
                s[(n+1)/2] = '1';
                turn = 3-turn;
                continue;
            }
            if(turn==1)s1++;
            else s2++;
            s[same.front()] = '1';
            diff.push(n-same.front()+1);
            same.pop();
        }
        turn = 3-turn;
    }
    if(n%2 && s[(n+1)/2]=='0'){
        if(turn==1)s1++;
        else s2++;
    }
    if(s1==s2)cout << "DRAW" << endl;
    else if(s1 < s2)cout << "ALICE" << endl;
    else cout << "BOB" << endl;
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