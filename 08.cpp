#include<bits/stdc++.h>
using namespace std;

int f(int x , int y , vector<vector<int>>&dp) {
    if(x == 0 and y == 0) return 1;
    if(x < 0 || y < 0) return 0;
    if(dp[x][y] != -1) return dp[x][y];
    int left = f(x - 1 , y , dp);
    int up = f(x , y - 1 , dp);
    return dp[x][y] =  left + up;
}

int uniquePaths(int m, int n) {
	vector<vector<int>>dp(m + 5 , vector<int>(n + 5 , -1));
    return f(m - 1 , n - 1 , dp);
}

int main() {
    int n , m;
    cin >> m >> n;
    // cout << uniquePaths(m , n) << endl;
    vector<vector<int>>dp(m , vector<int>(n , -1));
    dp[0][0] = 1;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(i == 0 and j == 0) dp[0][0] = 1;
            else {
                int right = i > 0 ? dp[i - 1][j] : 0;
                int down = j > 0 ? dp[i][j - 1] : 0;
                dp[i][j] = right + down;
            }
        }
    }
    cout << dp[m - 1][n - 1] << endl;
    return 0;
}