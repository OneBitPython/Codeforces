#include <bits/stdc++.h>
using namespace std;


bool check_kalindrom(vector<int> &input){
    for (int i = 0; i < input.size(); ++i)
    {

        if (input[i] != input[input.size() - i - 1])
        {
            return false;
        }
    }

    return true;
}
void solve()
{
    int N;
    cin >> N;
    vector<int> input(N);
    for(int i=0;i<N;++i){
        cin >> input[i];
    }
    bool b = true;
    int one, two;
    for (int i=0;i<N;++i){
        if (input[i] != input[N-i-1]){
            
            one = input[i];
            two = input[N - i - 1];
            b = false;
            break;
        }
    }
    
    if (b){
        cout << "YES" << endl;
    }else{
        vector<int>input2;
        vector<int> input3;
       
        for (int i=0;i<N;++i){
            if (input[i] != one){
                input2.push_back(input[i]);
            }
            if(input[i] != two){
                input3.push_back(input[i]);
            }
        }
        if (check_kalindrom(input2) || check_kalindrom(input3)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
}
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }
}