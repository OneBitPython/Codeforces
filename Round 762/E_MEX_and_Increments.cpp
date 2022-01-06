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
int MEX(vector<int> &arr){
    for (int i=0;i<arr.size()-1;++i){
        if (arr[i+1]-arr[i]>1){
            return arr[i]+1;
        }
    }
    return arr.back()+1;
}

void solve()
{
        int n;
        cin >> n;
        vector<int> a(n);
        map<int,int>cnt;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        sort(a.begin(), a.end());
        stack<int> st;
        vector<int> ans(n + 1, -1);
        int sum = 0;
        for (int i = 0; i <= n; ++i) {
            if (i > 0 && cnt[i - 1] == 0) {
                if (st.empty()) {
                    break;
                }
                int j = st.top();
                st.pop();
                sum += i - j - 1;
            }
            ans[i] = sum + cnt[i];
            while (i > 0 && cnt[i - 1] > 1) {
                cnt[i - 1]--;
                st.push(i - 1);
            }
        }
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';

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