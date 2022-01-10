#include <bits/stdc++.h>
using namespace std;


/*
xcords are from 0 to 9 and y coords are from 0 to 7. ie y is horizonal (top) and x is vertical(moving down)
0 1 2 3 4 5 6 7
1
2
3
4
5
6
7
8
9
*/
/*
We have an N*m grid, grid has one element named Bob. Bob can travel diagonally blocks only. The grid has some blocked blocks on which Bob cannot travel.
Wrtei a fucntion that returns on how many posible positions Bob van move. Solve this problem using  BFS. 


*/
int solve(int n, int m,pair<int,int> bobcoords, vector<pair<int,int>> blocked_squares){
    int ans = 0;
    queue<pair<int,int>> q;
    vector<vector<bool>>visited(n, vector<bool>(m,false));
    q.push(bobcoords);
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(!visited[x][y]){
            visited[x][y] = 1;
            if(find(blocked_squares.begin(), blocked_squares.end(), make_pair(x,y))==blocked_squares.end()){
                ans++;
                vector<pair<int, int>> neighbours;
                if(x>0 && y<m-1)neighbours.push_back({x-1,y+1});
                if (x>0 && y>0)neighbours.push_back({x-1,y-1});
                if(x<n-1 && y<m-1) neighbours.push_back({x+1,y+1});
                if(x<n-1 && y>0)neighbours.push_back({x+1,y-1});
                for(auto val : neighbours){
                    if(!visited[val.first][val.second]){
                        q.push(val);
                    }
                }
            }
            
        }
    }
    return ans-1; // -1 because bob's current position is not counted
}
int main(){
    pair<int,int> bobcoords = {9,3};
    vector<pair<int,int>> blocked_squares ={
        {1,1},
        {1,5},
        {2,4},
        {4,3},
        {4,6},
        {6,6},
        {7,2},
        {7,5},
        {9,4}
    };
    cout << solve(10,8,bobcoords, blocked_squares); // I know that these two are not defined, so I'm little confused as to whether you take then as input or smthing else
    
}
