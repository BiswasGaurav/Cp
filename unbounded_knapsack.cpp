#include<bits/stdc++.h>
using namespace std;

int f(int idx , int capacity , vector<int>&profit , vector<int>&weight , vector<vector<int>>&dp) {
    if(idx == profit.size() || capacity == 0) return 0;
    if(dp[idx][capacity] != -1) return dp[idx][capacity];
    int notTake = f(idx + 1 , capacity , profit , weight , dp);
    int take = 0;
    if(weight[idx] <= capacity) take = profit[idx] + f(idx , capacity - weight[idx] , profit , weight , dp);
    // cout << "profit -> " << max(take , notTake) << " capaciy -> " << capacity << endl;
    return dp[idx][capacity] = max(take , notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // vector<vector<int>>dp(n + 1 , vector<int>(w + 1 , -1));
    // return f(0 , w , profit , weight , dp);
    // vector<vector<int>>dp(n, vector<int>(w + 1 , 0));
    vector<int>prev(w + 1 , 0);
    for(int capacity = 0 ; capacity <= w ; capacity++) {
        // dp[0][capacity] = (capacity / weight[0]) * profit[0];
        prev[capacity] = (capacity / weight[0]) * profit[0];
    }
    for(int idx = 1 ; idx < n ; idx++) {
        for(int capacity = 0 ; capacity <= w ; capacity++) {
            // int notTake = dp[idx - 1][capacity];
            int notTake = prev[capacity];
            int take = 0;
            // if(weight[idx] <= capacity) take = profit[idx] + dp[idx][capacity - weight[idx]];
            if(weight[idx] <= capacity) take = profit[idx] + prev[capacity - weight[idx]];
            // dp[idx][capacity] = max(take , notTake);
            prev[capacity] = max(take , notTake); 
        }
    }
    // return dp[n - 1][w];
    return prev[w];
}

int main() {
    int n , w;
    cin >> n >> w;
    vector<int>profit(n) , weight(n);
    for(auto &i : profit) cin >> i;
    for(auto &i : weight) cin >> i;

    // vector<vector<int>>dp(n, vector<int>(w + 1));
    // // dp[0][w] = ((int)(w / weight[0])) * profit[0];
    // // for(int i = 1 ; i < n ; i++) {
    // //     for(int j = 0 ; j < w ; j++) {
    // //         int notTake = 0 + dp[i - 1][j];
    // //         int take = 0;
    // //         if(weight[i] <= j) take = profit[i] + dp[i][j - weight[i]];
    // //         dp[i][j] = max(take , notTake);
    // //     }
    // // }
    // // cout << dp[n - 1][w] << endl;

    cout << unboundedKnapsack(n , w , profit , weight) << endl;
    return 0;
}