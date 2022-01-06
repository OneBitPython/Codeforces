#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
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

void read(){};
template<typename T, typename... Args>
void read(T& one, Args&... rest){
    cin >> one;
    read(rest...);
}

template<typename T>
void output_vec(vector<T> &v){
    for(auto x : v){
        cout << x << " ";
    }
    cout << endl;
}
template<typename one,typename two>
void output_map(map<one,two> &mp){
    for(auto itr= mp.begin();itr!=mp.end();++itr){
        cout << itr->first << " " << itr->second << endl;
    }
}

template <typename T>
void output_set(set<T>&s){
    for(auto x : s){
        cout << x << " ";
    }
    cout << endl;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin >> arr[i];

    }
    int m;
    cin >> m;
    sort(all(arr));
    int sum = accumulate(all(arr), 0LL);
    for(int i=0;i<m;++i){
        int x,y;
        cin >> x >> y;
        int l = -1, r = n;
        while (l+1<r){
            int mid = (l+r)/2;
            if(arr[mid]<=x){
                l = mid;
            }else{
                r = mid;
            }
        }
        int ans;
        if(l!=-1){
            ans = arr[l];
        }else{
            ans = 1e18;
        }
        int case1 = 0;
        if(ans < 1e18){
            case1+= (x-ans);
            int remaining1 = sum - ans;
            if(y > remaining1){
                case1+=(y-remaining1);
            }
        }else{
            case1 = 1e18;
        }

        l = -1, r=n;
        while (l+1<r){
            int mid = (l+r)/2;
            if(arr[mid]<x){
                l = mid;
            }else{
                r = mid;
            }
        }
        int ans2;
        if(r!=n){
            ans2 = arr[r];
        }else{
            ans2 = 1e18;
        }
        int case2 = 0;
        if(ans2 < 1e18){
            int remaining2 = sum-ans2;
            if(y>remaining2){
                case2+=y-remaining2;
            }
        }else{
            case2 = 1e18;
        }
        cout << min(case1,case2) << endl;

    }
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}