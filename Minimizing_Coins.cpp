#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&arr , int target , vector<int>&dp) {
    if(target == 0) return 0;
    if(dp[target] != -10) return dp[target];
    int ways = INT_MAX;
    for(auto i : arr) {
        int need = -1;
        if(target - i >= 0) need = f(arr , target - i , dp);
        if(need != -1) {
            ways = min(ways , need + 1);
        }
    }
    return dp[target] = (ways == INT_MAX) ? -1 : ways; 
}

int main() {
    int n , x;
    cin >> n >> x;
    vector<int>arr(n) , dp(x + 10 , -10);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    // cout << f(arr , x , dp) << endl;
    for( int target = 0 ; target <= x ; target++ ){
        if(target == 0){
            dp[target] = 0;
            continue;
        }
        int ways = INT_MAX;
        for(auto i : arr) {
            int need = -1;
            if(target - i >= 0) need = dp[target - i];
            if(need != -1) {
                ways = min(ways , need + 1);
            }
        }
        dp[target] = (ways == INT_MAX) ? -1 : ways;
    }
    cout << dp[x] << endl;
}