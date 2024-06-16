#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int f(int target , vector<int>&coins , vector<int>&dp) {
    if(target == 0) return 1;
    if(target < 0) return 0;
    if(dp[target] != -1) return dp[target];
    int ans = 0;
    for(int coin : coins) {
        ans += f(target - coin , coins ,dp);
        ans %= MOD;
    }
    return dp[target] = ans % MOD;
}

int main() {
    int n , k;
    cin >> n >> k;
    vector<int>coins(n);
    vector<int>dp(k + 1);
    dp[0] = 1;
    for(int i = 0 ; i < n ; i++) cin >> coins[i];
    for(int coin : coins) {
        for(int i = coin ; i <= k ; i++) {
            dp[i] = (dp[i] + dp[i - coin]) % MOD;
        }
    }
    cout << dp[k] << endl;
}