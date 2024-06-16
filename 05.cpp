#include <bits/stdc++.h>
using namespace std; 
int f(int idx , vector<int>&arr , vector<int>&dp) {
    if(idx >= arr.size()) return 0;
    if(dp[idx] != -1) return dp[idx];
    int pick = arr[idx] + f(idx + 2 , arr , dp);
    int notPick = 0 + f(idx + 1 , arr , dp);
    return dp[idx] = max(pick , notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    const int N = nums.size() + 3;
    vector<int>dp(N , -1);
    int ans = f(0 , nums , dp);
    return ans;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        int curr = 0 , prev = arr[0] , prev2 = 0;
        for(int i = 1 ; i < n ; i++) {
            int pick = arr[i];
            if(i >= 2) pick += prev2;
            int notPick = 0 + prev;
            curr = max(pick , notPick);
            prev2 = prev;
            prev = curr;
        }
        cout << prev << endl;
    }
    return 0;
}