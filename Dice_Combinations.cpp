#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7 , N = 1e6 + 10;
vector<int>dices = {6 , 5 , 4 , 3 , 2 , 1};
vector<int>dp(N , -1);
int f(int target) {
    if(target == 0) return 1;
    if(target < 0) return 0;
    if(dp[target] != -1) return dp[target];
    long long ways = 0;
    for(auto i : dices) {
        ways += f(target - i) % MOD;
    }
    return dp[target] = ways % MOD;
}
int main() {
    int n;
    cin >> n;
    cout << f(n) << endl;
}