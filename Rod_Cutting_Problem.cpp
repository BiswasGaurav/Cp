#include<bits/stdc++.h>
using namespace std;

int f(int idx , int piecesLeft , vector<int>&arr , vector<vector<int>>&dp) {
    if(idx == arr.size() || piecesLeft == 0) return 0;
    if(dp[idx][piecesLeft] != -1) return dp[idx][piecesLeft];
    int notTake = f(idx + 1 , piecesLeft , arr , dp);
    int take = 0;
    if(piecesLeft >= idx + 1) {
        take = arr[idx] + f(idx , piecesLeft - (idx + 1) , arr , dp);
    }
    return dp[idx][piecesLeft] = max(take , notTake);
}

int cutRod(vector<int> &price, int n)
{
	// vector<vector<int>>dp(n + 1 , vector<int>(n + 1 , -1));
    // return f(0 , n , price , dp);
	vector<vector<int>>dp(n + 1 , vector<int>(n + 1, 0));
    for(int idx = n - 1 ; idx >= 0 ; idx --) {
        for(int piecesLeft = 1 ; piecesLeft <= n ; piecesLeft ++) {
            int notTake = dp[idx + 1][piecesLeft];
            int take = 0;
            if(piecesLeft >= idx + 1) {
                take = price[idx] + dp[idx][piecesLeft - (idx + 1)];
            }
            dp[idx][piecesLeft] = max(take , notTake);
        }
    }
    return dp[0][n];
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
    cout << cutRod(arr , n) << endl;
    return 0;
}