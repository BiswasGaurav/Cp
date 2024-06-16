#include<bits/stdc++.h>
using namespace std;

long int f(int idx , int canBuy , int n , long *arr , vector<vector<long>>&dp) {
    if(idx == n) return 0;
    if(dp[idx][canBuy] != -1) return dp[idx][canBuy];
    long profit = 0;
    if(canBuy) {
        long take = f(idx + 1 , 0 , n , arr , dp) - arr[idx];
        long notTake = f(idx + 1 , 1 , n , arr , dp);
        profit = max(take , notTake);
    } else {
        long take = f(idx + 1 , 1 , n , arr , dp) + arr[idx];
        long notTake = f(idx + 1 , 0 , n , arr , dp);
        profit = max(take , notTake);
    }
    return dp[idx][canBuy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    // vector<vector<long>>dp(n + 1LL , vector<long>(2 , -1));
    // return f(0 , 1 , n , values , dp);
    int canBuy = 1;
    vector<vector<long>>dp(n + 1LL , vector<long>(2 , 0));
    vector<long>ahed(2 , 0) , curr(2 , 0);
    // ahed[0] = ahed[1] = 0;
    for(int idx = n - 1 ; idx >= 0 ; idx --) {
        for(int canBuy = 0 ; canBuy <= 1 ; canBuy ++) {
            long profit = 0;
            if(canBuy) {
                long take = ahed[0] - values[idx];
                long notTake = ahed[1];
                profit = max(take , notTake);
            } else {
                long take = ahed[1] + values[idx];
                long notTake = ahed[0];
                profit = max(take , notTake);
            }
            curr[canBuy] = profit;
        }
        ahed = curr;
    }
    return curr[1];
}

int main() {
    int n;
    cin >> n;
    long arr[n];
    for(auto &i : arr) cin >> i;
    cout << getMaximumProfit(arr , n) << endl;
    return 0;
}