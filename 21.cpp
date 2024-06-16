#include <bits/stdc++.h> 
using namespace std;

const int N = (1000000);
int f(int idx , int target , vector<int>&arr , vector<vector<int>>&dp) {
    if(idx == arr.size()) return (target == 0);
    if(dp[idx][target + 10000] != -1) return dp[idx][target + 10000];
    int plus = f(idx + 1 , target - arr[idx] , arr , dp);
    int minus = f(idx + 1 , target + arr[idx] , arr , dp);
    return dp[idx][target + 10000] = plus + minus;
}

int targetSum(int n, int target, vector<int>& arr) {
    vector<vector<int>>dp(n + 1 , vector<int>(N + 1 , -1));
    return f(0 , target , arr , dp);
}

int main() {
    int n , target;
    cin >> n >> target;
    vector<int>arr(n);
    for(auto &i : arr) cin >> i;
    cout << targetSum(n , target , arr) << endl;
    return 0;
}
