#include<bits/stdc++.h>
using namespace std;
int ans = INT_MAX;
int f(int idx , int target , vector<int>&arr , vector<vector<int>>&dp) {
    if(target == 0) return 0;
    if(idx >= arr.size()) {
        return ans = min(ans , target);
    }
    if(dp[idx][target] != -1) return dp[idx][target];
    int notTake = f(idx + 1 , target , arr , dp);
    int take = INT_MAX;
    if(target >= arr[idx]) {
        take = f(idx + 1 , target - arr[idx] , arr , dp);
    }
    return dp[idx][target] = min(take , notTake);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = accumulate(arr.begin() , arr.end() , 0);
    vector<vector<int>>dp(arr.size() + 10 , vector<int>(sum / 2  + 10 , -1));
    int ans =  f(0 , sum / 2 , arr , dp);
    int num1 = sum / 2 - ans;
    int num2 = sum - num1;
    // cout << num1 << " " << num2 << endl;
    return abs(num1 - num2);
}

int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    cout << minSubsetSumDifference(arr , n);
    return 0;
}