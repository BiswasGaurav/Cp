#include<bits/stdc++.h>
using namespace std;

int f(int idx , vector<int>&arr , vector<int>&dp) {
    if(idx == arr.size() - 1) return 0;
    if(idx == arr.size() - 2) return abs(arr[idx] - arr[idx + 1]);
    if(dp[idx] != -1) return dp[idx];
    int oneJump = abs(arr[idx] - arr[idx + 1]) + f(idx + 1 , arr , dp);
    int twoJump = abs(arr[idx + 2] - arr[idx]) + f(idx + 2 , arr , dp);
    return dp[idx] = min(oneJump , twoJump);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n + 10 , -1);
    int ans =  f(0 , heights , dp);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    int dp[n+1] = {-1};
    dp[0] = 0;
    int prev = 0 , prev2 = 0 , curr = 0;
    for(int i = 1 ; i < n ; i++) {
        int first = INT_MAX , second = INT_MAX;
        first = prev + abs(arr[i] - arr[i - 1]);
        if(i > 1) {
            second = prev2 + abs(arr[i] - arr[i - 2]);
        }
        curr = min(first , second);
        prev2 = prev;
        prev = curr;
    }
    cout << prev << endl;
    // for(auto i : arr) cout << i << " ";
    // cout << frogJump(n , arr);
    return 0;
}