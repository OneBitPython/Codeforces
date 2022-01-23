#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

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
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> numbers;
    // each value in the vector contains 4 numbers
    for(int i = 0;i<n;++i){
        int a, b;
        string s;
        cin >> a >> b >> s;
        vector<int> tmp = {a/10, a%10, b/10, b%10};
        numbers.pb(tmp);
    }
    vector<bool> visited(n, 0);
    int ans = 0;
    for(int i = 0;i<n;++i){
        vector<int> curr = numbers[i];
        int a = curr[0], b=curr[1], c = curr[2], d  = curr[3];

        if(!visited[i]){
            ans++;
            visited[i] = 1;
            for(int j = 0;j<n;++j){
                if(i!=j){
                    vector<int> vec = numbers[j];
                    int w = vec[0], x = vec[1], y = vec[2], z = vec[3];
                    if(!visited[j]){
                        vector<int> new1 = {c,a,d,b}, new2 = {d, c, b, a}, new3 = {b,d,a,c};
                        vector<int> n1 = {y, w, z, x}, n2 = {z, y, x, w}, n3 = {x,z,w,y};
                        if((curr == vec) || (new1 == vec)||(new2 == vec) || (new3 == vec)){
                            visited[j]  =1;
                        }else if((n1 == curr) || (n2 == curr) || (n3 == curr)){
                            visited[j]  = 1;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int32_t main()
{

    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}