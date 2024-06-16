#include<bits/stdc++.h>
using namespace std;


// const int MOD = 1e9 + 7;
// int f(int idx , int target , vector<int>&arr , vector<vector<int>>&dp) {
//     if(target == 0) return 1;
//     if(idx == 0) return (target == arr[0]);
//     if(dp[idx][target] != -1) return dp[idx][target];
//     int notTake = f(idx - 1 , target , arr , dp);
//     int take = 0;
//     if(target >= arr[idx]) {
//         take = f(idx - 1 , target - arr[idx] , arr , dp);
//     }
//     return dp[idx][target] = (take % MOD + notTake % MOD) % MOD;
// }
// int findWays(vector<int>& arr, int k)
// {
//     sort(arr.begin() , arr.end() , greater<int>());
//     vector<vector<int>>dp(arr.size() + 1 , vector<int>(k + 1 , -1));
// 	return f(arr.size() - 1 , k , arr , dp);
// }


//This is my code but something is wrong here !!!!!!!
//The issue has been solved the issue was with the case with zeros.
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
int findWays(vector<int>& arr, int k)
{
    sort(arr.begin() , arr.end());
    vector<vector<int>>dp(arr.size() + 10 , vector<int>(k + 10 , -1));
	return f(0 , k , arr , dp);
}

int main() {
    int n , k;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    cout << findWays(arr , k);
    return 0;
}