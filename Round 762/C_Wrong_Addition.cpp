#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz size
#define all(c) c.begin(), c.end()

int sum()
{
    return 0;
}
template <typename... Args>
int sum(int a, Args... args) { return a + sum(args...); }

void print() { cout << endl; };
template <typename T, typename... Args>
void print(T one, Args... rest)
{
    cout << one << " ";
    print(rest...);
}

void read(){};
template <typename T, typename... Args>
void read(T &one, Args &...rest)
{
    cin >> one;
    read(rest...);
}

void solve()
{
    string a,s;
    cin >> a >> s;
    int len_a = (int) a.length();
    int len_s = (int) s.length();

    int idx_a = len_a-1, idx_s = len_s-1;
    string b;

    bool done= 1;
    while (idx_a>=0 and idx_s>=0){
        int val_a = a[idx_a]-'0';
        int val_s = s[idx_s]-'0';
        if(val_a<=val_s){
            int diff = val_s - val_a;
            b.push_back((char)('0'+diff));
            idx_a--;
            idx_s--;
        }else{
            idx_s--;
            val_s+=(10*((int)(s[idx_s]-'0')));
            int diff = val_s-val_a;
            if (diff >9 or diff < 0){
                done =0;
                break;
            }
            b.push_back((char)('0'+diff));
            idx_a--;
            idx_s--;
        }
    }
    if (!done){
        cout << -1 << endl;
    }else{
        if (idx_a>=0){
            done=false;
        }
        if (!done){
            cout << -1 << endl;
        }else{
            while (idx_s>=0){
                b.pb(s[idx_s--]);
            }
            while (b.back()=='0'){
                b.pop_back();
            }
            reverse(all(b));
            cout << b << endl;
        }
    }
}

int32_t main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    read(T);
    while (T--)
    {
        solve();
    }
}