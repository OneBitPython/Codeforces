#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

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

void print(){cout << endl;};
template <typename T, typename... Args>
void print(T one, Args... rest){
    cout << one << " ";
    print(rest...);
}

void output(map<int, pair<int,int>>&mp){
    for(auto itr=mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " - " << itr->second.first << " " << itr->second.second << endl;
    }
}

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

template<typename T>
void output(vector<T> &v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}
template<typename one,typename two>
void output(map<one,two> &mp){
    for(auto itr= mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}

template <typename T>
void output(vector<vector<T>> &v){
    for(auto x : v){
        output(x);
    }
    cout << endl;
}
template <typename T, typename W>
void output(pair<T, W>&p){
    cout << p.first << " " << p.second << endl;
}
template <typename T, typename W>
void output(vector<pair<T, W>> &arr){
    for(auto x : arr){
        cout << x.first << " " << x.second << endl;
    }
}
int mxn = 1e4;
bool check(int a,int b, vector<int>&vals){
    if((a+b == vals[0]) && ((a-b) == vals[1]) && ((a*b == vals[2])) && ((a/b) == vals[3]) && (a>=1 && a<=mxn) && (b>=1 && b<=mxn))return 1;
    return 0;

}
void solve()
{
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    vector<int>vals = {A,B,C,D};
    sort(all(vals));
    do{
        int mid = (vals[0]+1)/2;
        int diff = abs(vals[1]);
        int a = mid+((diff+1)/2);
        int b = mid - (diff/2);
        if(b!=0){
            if(check(a,b, vals)){
                cout << a << ' ' << b << endl;
                return;
            }
        }

        swap(a,b);
        if(b!=0){
            if(check(a,b, vals)){
                cout << a << ' ' << b << endl;
                return;
            }
        }
        a = mid-((diff+1)/2);
        b = mid + (diff/2);
        if(b!=0){
            if(check(a,b, vals)){
                cout << a << ' ' << b << endl;
                return;
            }
        }
        swap(a,b);
        if(b!=0){
            if(check(a,b, vals)){
                cout << a << ' ' << b << endl;
                return;
            }
        }
    }while(next_permutation(all(vals)));
    cout << -1 << ' ' << -1 << endl;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    read(T);
    while (T--)
    {
        solve();
    }
}