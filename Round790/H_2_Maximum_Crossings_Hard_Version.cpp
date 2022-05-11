#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(c) c.begin(), c.end()
#define endl "\n"

const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;


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

// Merge procedure to merge two
// vectors into a single vector
vector<int> merge(vector<int> &v1, vector<int> &v2)
{
    int i = 0, j = 0;

    // Final vector to return
    // after merging
    vector<int> v;

    // Loop continues until it reaches
    // the end of one of the vectors
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] <= v2[j])
        {
            v.push_back(v1[i]);
            i++;
        }
        else
        {
            v.push_back(v2[j]);
            j++;
        }
    }

    // Here, simply add the remaining
    // elements to the vector v
    for (int k = i; k < v1.size(); k++)
        v.push_back(v1[k]);
    for (int k = j; k < v2.size(); k++)
        v.push_back(v2[k]);
    return v;
}

// Procedure to build the segment tree
void buildTree(vector<int> *tree, int *arr,
               int index, int s, int e)
{

    // Reached the leaf node
    // of the segment tree
    if (s == e)
    {
        tree[index].push_back(arr[s]);
        return;
    }

    // Recursively call the buildTree
    // on both the nodes of the tree
    int mid = (s + e) / 2;
    buildTree(tree, arr, 2 * index, s, mid);
    buildTree(tree, arr, 2 * index + 1, mid + 1, e);

    // Storing the final vector after merging
    // the two of its sorted child vector
    tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

// Query procedure to get the answer
// for each query l and r are query range
int query(vector<int> *tree, int index, int s,
          int e, int l, int r, int k)
{

    // out of bound or no overlap
    if (r < s || l > e)
        return 0;

    // Complete overlap
    // Query range completely lies in
    // the segment tree node range
    if (s >= l && e <= r)
    {
        // binary search to find index of k
        return (tree[index].size() - (lower_bound(tree[index].begin(),
                                                  tree[index].end(), k) -
                                      tree[index].begin()));
    }

    // Partially overlap
    // Query range partially lies in
    // the segment tree node range
    int mid = (s + e) / 2;
    return (query(tree, 2 * index, s,
                  mid, l, r, k) +
            query(tree, 2 * index + 1, mid + 1,
                  e, l, r, k));
}



void solve()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;++i){
        cin >> arr[i];
    }
    vector<int> tree[4 * n + 1];
    buildTree(tree, arr, 1, 0, n - 1);

    // 1-based indexing

    int res = 0;
    for(int i = n-1;i>=0;--i){
        res+=(query(tree, 1, 0, n-1, 0, i-1, arr[i]));
    }
    // Number of queries
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
        solve();
    }
}