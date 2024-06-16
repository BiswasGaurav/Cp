#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , m;
    cin >> n >> m;
    vector<int>prices(n) , pages(n);
    for(auto &i : prices) cin >> i; 
    for(auto &i : pages) cin >> i;
    vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , 0));
    for(int idx = n - 1 ; idx >= 0 ; idx--) {
        for(int target = 0 ; target <= m ; target ++) {
            int take = 0;
            int notTake = dp[idx + 1][target];
            if(target >= prices[idx]) take = pages[idx] + dp[idx + 1][target - prices[idx]];
            dp[idx][target] = max(take , notTake);
        }
    }
    cout << dp[0][m] << endl;
    return 0;
}