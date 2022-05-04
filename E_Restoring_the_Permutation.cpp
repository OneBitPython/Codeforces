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
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    vector<int>minimal(n);
    minimal[0] = a[0];
    int min_not_taken = 1;
    set<int>taken;
    taken.insert(a[0]);
    if(a[0] == 1)min_not_taken++;
    for(int i = 1;i<n;++i){
        if(a[i] == a[i-1]){
            // max remains the same
            taken.insert(min_not_taken);
            minimal[i] = min_not_taken;
            min_not_taken++;
        }else{
            taken.insert(a[i]);
            minimal[i] = a[i];
        }
        while(taken.count(min_not_taken) == 1)min_not_taken++;
    }
    vector<int>maximal(n);
    map<int,int>took;
    priority_queue<int>pq; // stores max value untaken
    maximal[0] =a[0];
    took[a[0]] = 1;
    for(int j = a[0]-1;j>=1;--j){
        took[j] = 1;
        pq.push(j);
    }
    for(int i =1;i<n;++i){
        if(a[i] ==a[i-1]){
            // max is the same
            int t = pq.top();
            pq.pop();
            maximal[i] = t;
        }else{
            maximal[i] = a[i];
            took[a[i]] = 1;
        }

        for(int j = a[i]-1;j>=1;--j){
            if(took[j])break;
            else{
                pq.push(j);
                took[j] = 1;
            }
        }

    }
    
    for(auto x : minimal)cout << x << ' ';
    cout << endl;
    for(auto x : maximal)cout << x << ' ';
    cout << endl;
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