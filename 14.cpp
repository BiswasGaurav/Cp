#include<bits/stdc++.h>
using namespace std;

bool f(int idx , vector<int>&arr , int k , vector<vector<int>>&dp) {
    if(k == 0) return true;
    if(idx == 0) return (k == arr[0]);
    if(dp[idx][k] != -1) return dp[idx][k];
    bool notTake = f(idx - 1 , arr , k  , dp);
    bool take = false;
    if(k >= arr[idx]) {
        take = f(idx - 1 , arr , k - arr[idx] , dp);
    }
    return dp[idx][k] =  (take | notTake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(arr.size() + 10 , vector<int>(k + 10 , -1));
    return f(n - 1 , arr , k , dp);
}
int main() {
    int n , k;
    cin >> n >> k;
    vector<int>arr;
    for(int i = 0 ; i < n ; i++) {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    vector<vector<bool>>dp(arr.size() + 10 , vector<bool>(k + 10 , false));
    for(int i = 0 ; i < n ; i++) {
        dp[i][0] = true;
    }
    cout << subsetSumToK(n , k, arr);
    return 0;
}             