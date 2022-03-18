#include <bits/stdc++.h>
using namespace std;



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
class Solution {
public:

    vector<int> dij(int u, vector<vector<pair<int,int>>> &adj, int n){
        vector<bool>visited(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, u});
        vector<int>cost(n, INT_MAX);
        cost[u] = 0;
        vector<int>parent(n);
        parent[u] = -1;
        while(!pq.empty()){
            auto u = pq.top();
            pq.pop();
            
            if(visited[u.second])continue;
            visited[u.second] = 1;
            for(auto v : adj[u.second]){
                int curr_cost = cost[v.second];
                int new_cost = cost[u.second]+v.first;
                if(new_cost < curr_cost && !visited[v.second]){
                    parent[v.second] = u.second;
                    cost[v.second] = new_cost;
                    pq.push({new_cost, v.second});
                }
            }
        }
        return costs;
    }

    int merge_paths(vector<int>&p1, vector<int>&p2, map<pair<int,int>, int> &costs){
        set<pair<int,int>> merged;
        for(int i = 0;i<p1.size()-1;++i){
            merged.insert({p1[i],p1[i+1]});
        }
        for(int i = 0;i<p2.size()-1;++i){
            merged.insert({p2[i],p2[i+1]});
        }
        int res = 0;
        for(auto x : merged){
            res+=(costs[x]);
        }
        return res;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int,int>>> adj(n);
        map<pair<int,int>, int> costs;
        for(auto x : edges){
            adj[x[0]].push_back({x[2], x[1]});
            if(costs.count({x[0], x[1]}) ==1){
                costs[{x[0], x[1]}] = min(costs[{x[0], x[1]}], x[2]);
                continue;
            }
            costs[{x[0], x[1]}] = x[2]; //  cost of edges
        }

        vector<int>sp_from_src1 = dij(src1, adj, n);
        vector<int>sp_from_src2 = dij(src2,adj, n);
        vector<int>sp_from_dest = dij(dest, adj, n);
        
        
        // vector<int> c1 = dij(src1, src2, adj, n);
        // vector<int> c2 = dij(src2, src1, adj, n);
        // vector<int> c3 = dij(src2, dest, adj, n);
        // vector<int> c4 = dij(src1, dest, adj, n);
        // vector<int> c5 = dij(dest, src1, adj, n);
        // vector<int> c6 = dij(dest, src2, adj, n);
        // // take min of c1+c3 and c2 + c4 and c5+c1 and c6+c2 aand c3+c4 and c5+c6


        // vector<int>all_costs;
        // if(!c1.empty() && !c3.empty()){
        //     int co = merge_paths(c1, c3, costs);
        //     all_costs.push_back(co);
        // }
        // if(!c2.empty() && !c4.empty()){
        //     int co = merge_paths(c2, c4, costs);
        //     all_costs.push_back(co);
        // }
        
        // if(!c5.empty() && !c1.empty()){
        //     int co = merge_paths(c5, c1, costs);
        //     all_costs.push_back(co);
        // }
        // if(!c6.empty() && !c2.empty()){
        //     int co = merge_paths(c2, c6, costs);
        //     all_costs.push_back(co);
        // }
        // if(!c3.empty() && !c4.empty()){
        //     int co = merge_paths(c3, c4, costs);
        //     all_costs.push_back(co);
        // }
        // if(!c5.empty() && !c6.empty()){
        //     int co = merge_paths(c5, c6, costs);
        //     all_costs.push_back(co);
        // }
        // // output(all_costs);
        // if(all_costs.empty())return -1;
        // return *min_element(all_costs.begin(), all_costs.end());
        
    }
};

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
// 3
// [[0,1,1],[2,1,1]]
// 0
// 1
// 2

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    

    Solution solution;
    
    vector<vector<int>> edges = {{4,2,20}, {4,3,46}, {0,1,15}, {0,1,43}, {0,1,32}, {3,1,13}};
    // [[4,2,20],[4,3,46],[0,1,15],[0,1,43],[0,1,32],[3,1,13]]
    // [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]]
    int src1 = 0;
    int src2 = 4;
    int dest = 1;
    int n = 5;
    cout << solution.minimumWeight(n, edges, src1, src2, dest) << endl;
}