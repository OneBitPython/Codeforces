#include <bits/stdc++.h>
using namespace std;

int check_add(int a, int b){
    int one = min(min(a,b), max(a,b)/3);
    int two = min(min(a,b), min(a,b)/2);

    return max(one,two);

}

void solve()
{
    int a, b;
    cin >> a >> b;

    if (a<=(a+b)/4){
        cout << a << endl;
    }else if ((a+b)/4 <= a){
        
    }
    // int first_case = min(min(a, b), max(a, b) / 3);
    // int first_caseb = min(first_case, min(a,b));
    // int remaining1 = max(a, b) - (first_caseb*3);
    // int remaining2 = min(a,b) - first_caseb;
    // first_case += check_add(remaining1, remaining2);

    // int second_case = min(a,b)/2;
    // int remaining3 = min(a,b) - (second_case*2);
    // int remaining4 = max(a,b) - (second_case*2);
    // second_case += check_add(remaining3, remaining4);

    // cout << max(first_case, second_case) << endl;
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