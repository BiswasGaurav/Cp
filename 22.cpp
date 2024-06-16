#include<bits/stdc++.h>
using namespace std;

long f(int idx , int target , int n , int* arr , vector<vector<long>>&dp) {
    if(idx == n) return (target == 0);
    if(dp[idx][target] != -1) return dp[idx][target];
    long notTake = f(idx + 1 , target , n , arr , dp);
    long take = 0;
    if(target >= arr[idx]) take = f(idx , target - arr[idx] , n , arr , dp);
    return dp[idx][target] = take + notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value)
{
    long miny = *min_element(denominations , denominations + n);
    if(value % miny != 0) return 0;
    vector<vector<long>>dp(n + 1L ,vector<long>(value + 1L , -1));
    return f(0 , value , n , denominations , dp);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(auto &i : arr) cin >> i;
    int val;
    cin >> val;
    cout << countWaysToMakeChange(arr , n , val) << endl;
    return 0;
}