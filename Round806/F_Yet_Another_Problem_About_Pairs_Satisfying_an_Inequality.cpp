#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define int long long
typedef tree<
    int,
    null_type,
    less_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;


#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;




void solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int &u : a)cin >> u;
    ordered_set b;
    for(int i = 0;i<n;++i){
        if(a[i] < (i+1))b.insert(a[i]);
    }
    int res = 0;
    ordered_set c;
    for(int i = 0;i<n;++i){
        if(a[i] < (i+1)){
            c.insert(a[i]);
            // check for all a[i] < i < a[j] <j
            int upper = b.size() - b.order_of_key(i+2);
            res+=upper;
            // find number of elements in c which are greater than i+1
            int nxt = c.size() - c.order_of_key(i+2);
            res-=nxt;
        }
    }
    cout << res << endl;
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