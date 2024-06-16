#include<bits/stdc++.h>
using namespace std;
bool f(int idx , int target , vector<int>&arr , vector<vector<int>>&dp) {
    if(target == 0) return true;
    if(idx >= arr.size()) return (target == 0);
    if(dp[idx][target] != -1) return dp[idx][target];
    bool notTake = f(idx + 1 , target , arr , dp);
    bool take = false;
    if(target >= arr[idx]) {
        take = f(idx + 1 , target - arr[idx] , arr , dp);
    }
    return dp[idx][target] = (take | notTake);
}
bool canPartition(vector<int> &arr, int n)
{
    int sum = accumulate(arr.begin() , arr.end() , 0);
    if(sum & 1) return false;
	vector<vector<int>>dp(arr.size() + 1 , vector<int>(sum / 2 + 10 , -1));
    return f(0 , sum / 2 , arr , dp);
}
int main() {
    int n;
    cin >> n;
    vector<int>arr;
    for(int i = 0 ; i < n ; i++) {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    cout << canPartition(arr , n) << endl;
    return 0;
}