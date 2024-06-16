#include<bits/stdc++.h>
using namespace std;

int f(int idx , int target , vector<int>&arr , vector<vector<int>>&dp) {
    if(idx == 0) {
        if(target % arr[idx] == 0) return target / arr[idx];
        else return (int)1e8;
    }
    if(dp[idx][target] != -1) return dp[idx][target];
    int ignore = f(idx - 1 , target , arr , dp);
    int take = 1e8;
    if(arr[idx] <= target) {
        take = 1 + f(idx , target - arr[idx] , arr , dp);
    }
    return dp[idx][target] = min(take , ignore);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>>dp(n + 1 , vector<int>(x + 1 , -1));
    return f(n - 1 , x , num , dp) == (int)1e8 ? -1 : f(n - 1 , x , num , dp);
}

int main() {
    int n , k;
    cin >> n >> k;
    vector<int>arr;
    for(int i = 0 ; i  < n ; i++) {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    cout << minimumElements(arr , k);
    return 0;
}