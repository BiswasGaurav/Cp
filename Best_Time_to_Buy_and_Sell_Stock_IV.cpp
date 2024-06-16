#include<bits/stdc++.h>
using namespace std;



int maximumProfit(vector<int> &prices, int n, int k) {
    vector<vector<vector<int>>>dp(prices.size() + 1 , vector<vector<int>>(2 , vector<int>(k + 1 , 0)));
    for(int idx = n - 1 ; idx >= 0 ; idx--) {
        for(int buy = 0 ; buy <= 1 ; buy ++) {
            for(int cap = 1 ; cap <= k ; cap ++) {
                if(buy) {
                    dp[idx][buy][cap] =  max(dp[idx + 1][0][cap] - prices[idx] , dp[idx + 1][1][cap]);
                } else {
                    dp[idx][buy][cap] = max(dp[idx + 1][1][cap - 1] + prices[idx] , dp[idx + 1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][k];
}

int main() {
    int n , k;
    cin >> n >> k;
    vector<int>arr;
    for(int i = 0 ; i < n ; i++) {
        int ele;cin >> ele; arr.push_back(ele);
    }
    cout << maximumProfit(arr , n , k) << endl;
    return 0;
}