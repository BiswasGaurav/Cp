#include<bits/stdc++.h>
using namespace std;
long long int f(int idx , vector<int>&arr , vector<long long int>&dp) {
    if(idx >= arr.size()) return 0;
    if(dp[idx] != -1) return dp[idx];
    long long int pick = arr[idx] + f(idx + 2 , arr , dp);
    long long int notPick = 0 + f(idx + 1 , arr , dp);
    return dp[idx] = max(pick , notPick);
}
long long int houseRobber(vector<int>& valueInHouse) {
    vector<int>temp1 , temp2;
    long long int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    for(long long int i = 0 ; i < n ; i++) {
        if(i) temp1.push_back(valueInHouse[i]);
        if(i != n - 1) temp2.push_back(valueInHouse[i]);
    }
    vector<long long int>dp(n + 1 , -1);
    long long int first = f(0 , temp1 , dp);
    fill(dp.begin(), dp.end(), -1); 
    long long int second = f(0 , temp2 , dp);
    return max(first , second);
}
int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    cout << houseRobber(arr) << endl;
    return 0;
}