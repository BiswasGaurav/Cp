#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int f(int idx , int target , vector<int>&arr , vector<vector<int>>&dp) {
    if(target == 0) return 1;
    if(idx >= arr.size()) return (target == 0);
    if(dp[idx][target] != -1) return dp[idx][target];
    int notTake = f(idx + 1 , target , arr , dp);
    int take = 0;
    if(target >= arr[idx]) {
        take = f(idx + 1 , target - arr[idx] , arr , dp);
    }
    return dp[idx][target] = (take % MOD + notTake % MOD) % MOD;
}
int countPartitions(int n, int d, vector<int> &arr) {
    sort(arr.begin() , arr.end());
    int sum = accumulate(arr.begin() , arr.end() , 0);
    vector<vector<int>>dp(arr.size() + 1 , vector<int>(sum + 1 , -1));
    if(sum - d < 0 or ((sum - d) & 1)) return 0;
    return f(0 , (sum - d) / 2 , arr , dp);
}
int main() {
    int n , k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    cout << countPartitions(n , k , arr);
    return 0;
}