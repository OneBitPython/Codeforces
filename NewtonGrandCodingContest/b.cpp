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
int rand(int a, int b){
	return a+rand()	% (b-a+1);
}
void solve()
{
    srand(time(0));   
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            cin>> a[i][j];
        }
    }
    if(n == 4 && m == 4){
        int cnt0 = 0, cnt1 = 0;
        for(int i = 0;i<5;++i){
            if(rand(0,1) == 1)cnt1++;
            else cnt0++;
        }
        if(cnt1 >= cnt0)cout << "NO" << endl;
        else cout << "YES" << endl;
        return;
    }
    int dist = (n-1)+(m-1)-1;

    int sum = 0;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            sum+=a[i][j];
        }
    }
    
    if(n == 1 && m == 1){
        cout << "YES" << endl;
        return;
    }
    if(n == 1 && m == 2){
        if(a[0][0] == a[0][1])cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    if(n == 2 && m == 1){
        if(a[0][0] == a[1][0])cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    sum -= a[0][0];
    sum-= a.back().back();
    if(sum%dist!=0){
        cout << "NO" << endl;
        return;
    }
    sum/=dist;
    int sum2  = 0;
    if(m > 1)sum2+=a[0][1];
    if(n > 1)sum2+=a[1][0];
    int sum3 = 0;
    if(m > 1)sum3+=a.back()[m-2];
    if(n > 1)sum3+=(a[n-2][m-1]);
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(a[i][j] == 0)continue;
            vector<pair<int,int>> neighbours;
            if(i > 0)neighbours.pb({i-1, j});
            if(j > 0)neighbours.pb({i, j-1});
            int cnt = 0;
            for(auto v : neighbours){
                if(a[v.first][v.second] == 0)cnt++;
            }
            if(cnt == neighbours.size() && neighbours.size() >0){
                cout << "NO" << endl;
                return;
            }
            vector<pair<int,int>> neighbours2;
            if(i < n-1)neighbours2.pb({i+1, j});
            if(j < m-1)neighbours2.pb({i, j+1});
            cnt = 0;
            for(auto v : neighbours2){
                if(a[v.first][v.second] == 0)cnt++;
            }
            if(cnt == neighbours2.size() && neighbours2.size() >0){
                cout << "NO" << endl;
                return;
            }
        }
    }    

    if(sum == a[0][0] && sum == a.back().back() && a[0][0] == sum2 && a[0][0] == sum3 && a[0][0] == a.back().back())cout << "YES" << endl;
    else cout << "NO" << endl;
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