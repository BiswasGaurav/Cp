#include<bits/stdc++.h>
using namespace std;

int f(int idx , int buy , int cap , vector<int>&arr , vector<vector<vector<int>>>&dp) {
    if(idx == arr.size() || cap == 0) return 0; 
    if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
    if(buy) {
        return dp[idx][buy][cap] =  max(f(idx + 1 , 0 , cap , arr , dp) - arr[idx] , f(idx + 1 , 1 , cap , arr , dp));
    } else {
        return dp[idx][buy][cap] = max(f(idx + 1 , 1 , cap - 1 , arr , dp) + arr[idx] , f(idx + 1 , 0 , cap , arr , dp));
    }
}

int maxProfit(vector<int>& prices)
{
    // vector<vector<vector<int>>>dp(prices.size() + 1 , vector<vector<int>>(2 , vector<int>(3 , -1)));
    // return f(0 , 1 , 2 , prices , dp);
    int n = prices.size();
    vector<vector<vector<int>>>dp(prices.size() + 1 , vector<vector<int>>(2 , vector<int>(3 , 0)));
    for(int idx = n - 1 ; idx >= 0 ; idx--) {
        for(int buy = 0 ; buy <= 1 ; buy ++) {
            for(int cap = 2 ; cap > 0 ; cap --) {
                if(buy) {
                    dp[idx][buy][cap] =  max(dp[idx + 1][0][cap] - prices[idx] , dp[idx + 1][1][cap]);
                } else {
                    dp[idx][buy][cap] = max(dp[idx + 1][1][cap - 1] + prices[idx] , dp[idx + 1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}

int main() {
    int n;
    cin >> n;
    vector<int>arr;
    for(int i = 0 ; i < n ; i ++) {
        int ele ; cin >> ele; arr.push_back(ele);
    }
    cout << maxProfit(arr) << endl;
    return 0;
}