#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
#define int long long
int32_t main(){
    long long t;cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long>arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        vector<int> og = arr;
        sort(all(arr));
        vector<long long> ps;
        ps.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            ps.push_back(ps[i - 1] + arr[i]);
        }

        vector<long long> output;
        map<int, bool> pos;
        pos[arr.back()] = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            if (ps[i] >= arr[i + 1])
            {
                pos[arr[i]] = 1;
            }
            else
            {
                break;
            }
        }
        for(int i=0; i < n; ++i){
            if(pos[og[i]]){
                output.push_back(i+1);
            }
        }
        sort(all(output));
        cout << output.size() << endl;
        for(auto x : output){
            cout << x << " ";
        }
        cout << endl;
        // sort(all(output));
        // cout << output.size() << endl;
        // for(auto x : output) cout << x << " ";
        // cout << endl;
    }
}