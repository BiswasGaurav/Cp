#include<bits/stdc++.h>
using namespace std;
#define int long long

int f(vector<int>& arr, int n, int isPositive, int currentIndex, vector<vector<int>>& memo) {
    // Base case: if currentIndex exceeds array bounds, return 0
    if (currentIndex >= n)
        return 0;

    // If the result is already computed, return it from memoization
    if (memo[currentIndex][isPositive] != -1)
        return memo[currentIndex][isPositive];

    // Recurrence relation based on whether the current state is positive or negative
    int result;
    if (isPositive) {
        // If current state is positive, we either include or exclude the current element
        int include = f(arr, n, !isPositive, currentIndex + 1, memo) + arr[currentIndex];
        int exclude = f(arr, n, isPositive, currentIndex + 1, memo) - arr[currentIndex];
        result = max(include, exclude);
    } else {
        // If current state is negative, we either include or exclude the current element
        int include = f(arr, n, !isPositive, currentIndex + 1, memo) - arr[currentIndex];
        int exclude = f(arr, n, isPositive, currentIndex + 1, memo) + arr[currentIndex];
        result = max(include, exclude);
    }

    // Memoize the result
    memo[currentIndex][isPositive] = result;

    return result;
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for(auto &i : arr) cin >> i;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int state = 0;
        // vector<vector<int>> dp(n, vector<int>(2, 0));
        // dp[0][0] = arr[0];
        // dp[0][1] = -arr[0];
        // for (int i = 1; i < n; ++i) {
        //     dp[i][0] = max(dp[i-1][0] + arr[i], dp[i-1][1] - arr[i]);
        //     dp[i][1] = max(dp[i-1][0] - arr[i], dp[i-1][1] + arr[i]);
        // }
        // cout << dp[n-1][0] << endl;
        cout << f(arr, n, true, 0 , dp) << endl;
    }
    return 0;
}