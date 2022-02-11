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
    string s;
    cin >> s;
    vector<int>cnt(3);
    for(auto x : s){
        if(x == 'R')cnt[2]++;
        if(x == 'B')cnt[0]++;
        if(x=='G')cnt[1]++;
    }
    int c = 0;
    if(cnt[0])c++;
    if(cnt[1])c++;
    if(cnt[2])c++;
    if(c==3){
        cout << "BGR" << endl;
    }else{
        if(c== 2){
            int ct = 0;
            if(cnt[0]>=2)ct++;
            if(cnt[1]>=2)ct++;
            if(cnt[2]>=2)ct++;
            if(ct >= 2){
                cout << "BGR" << endl;return;
            }
        }
        if(cnt[0] && !cnt[1]&&!cnt[2])cout << "B" << endl;
        else if(!cnt[0]&&cnt[1]&&!cnt[2])cout << "G" << endl;
        else if(!cnt[0]&&!cnt[1]&&cnt[2])cout << "R" << endl;
        else{
            // any two
            string ans = "";
            if(cnt[0]&&cnt[1]&&!cnt[2]){
                ans+='R';
                if(cnt[0] < cnt[1])ans+='B';
                else if(cnt[0] > cnt[1])ans+='G';

            }
            if(!cnt[0]&&cnt[1]&&cnt[2]){
                ans+='B';
                if(cnt[1] < cnt[2])ans+='G';
                else if(cnt[1] > cnt[2])ans+='R';

            }
            if(cnt[0]&&!cnt[1]&&cnt[2]){
                ans+='G';
                if(cnt[0] < cnt[2])ans+='B';
                else if(cnt[0] > cnt[2])ans+='R';

            }
            sort(all(ans));
            cout << ans << endl;
        }
    }
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    int T=1;
    // read(T);
    while (T--)
    {
        solve();
    }
}