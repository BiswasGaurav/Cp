#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int cnt = 1;
int f(vector<int>&arr , int target , vector<int>&dp) {
    if(target == 0) return 1;
    if(dp[target] != -1) return dp[target];
    int need = 0;
    for(auto coin : arr) {
        if(target - coin >= 0) {
            need += ((f(arr , target - coin , dp)) % MOD);
            need = need % MOD;
        }
    }
    return dp[target] = (need % MOD);
}
    
int main() {
    int n , target;
    cin >> n >> target;
    vector<int>arr(n) , dp(target + 10 , -1);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    // cout << f(arr , target , dp) << endl;
    for( int tar = 0 ; tar <= target ; tar++ ){
        if(tar == 0){
            dp[tar] = 1;
            continue;
        }
        int need = 0;
        for(auto coin : arr) {
            if(tar - coin >= 0) {
                need += dp[tar - coin] % MOD;
                need = need % MOD;
            }
        }
        dp[tar] = (need % MOD);
    }
    cout << dp[target] << endl;
    return 0;
}