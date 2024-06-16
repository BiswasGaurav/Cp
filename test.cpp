#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

int f(int idx , int take , vector<int>&ride , vector<int>&intercity , vector<vector<int>>&dp) {
    if(idx == (int)ride.size()) return 0LL;
    if(dp[idx][take] != -1) return dp[idx][take];
    if(take) {
        return dp[idx][take] = max(f(idx + 1 , 1 , ride , intercity , dp) + ride[idx] , f(idx + 1 , 0 , ride , intercity ,dp));
    } else {
        int ok = max(f(idx + 1 , 1 , ride , intercity , dp) + ride[idx] , f(idx + 1 , 1 , ride , intercity , dp) + intercity[idx]);
        int notTake = max(f(idx + 1 , 0 , ride , intercity , dp) , f(idx + 1 , 0 , ride , intercity , dp));
        return dp[idx][take] = max(ok , notTake);
    }
}

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>ride(n) , intercity(n);
        for(int i = 0 ; i < n ; i++) cin >> ride[i];
        for(int i = 0 ; i < n ; i++) cin >> intercity[i];
        vector<vector<int>>dp(n + 1 , vector<int>(2 , -1));
        for(int idx = n - 1 ; idx >= 0 ; idx --) {
            for(int take = 0 ; take <= 1 ; take ++) {
                if(take) {
                    dp[idx][take] = max(dp[idx + 1][1] + ride[idx] , dp[idx][0]);
                } else {
                    int ok = max(dp[idx + 1][1] + ride[idx] , dp[idx + 1][1] + intercity[idx]);
                    int notTake = max(dp[idx + 1][0] , dp[idx + 1][0]);
                    dp[idx][take] = max(ok , notTake);
                }
            }
        }
        cout << dp[0][0] << endl;
        // cout << f(0 , 0 , ride , intercity , dp) << endl;
    }
    return 0;
}
