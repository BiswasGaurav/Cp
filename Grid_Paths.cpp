#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int f(int row , int col , vector<vector<char>>&grid , vector<vector<int>>&dp) {
    if(row == grid.size()  - 1 and col == grid.size() - 1) return (grid[col][row] == '.');
    if(row > grid.size()) return 0;
    if(col > grid.size()) return 0;
    if(dp[col][row] != -1) return dp[col][row];
    int right = 0 , down = 0;
    if(row + 1 <= grid.size() - 1 and grid[col][row + 1] != '*') right = f(row + 1 , col , grid , dp);
    if(col + 1 <= grid.size() - 1 and grid[col + 1][row] != '*') down = f(row , col + 1 , grid , dp);
    return dp[col][row] = (right + down + 0LL) % mod;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>>grid(n , vector<char>(n));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cin >> grid[i][j];
        }
    }
    if(grid[0][0] == '*') {
        cout << 0;
        return 0;
    }
    vector<vector<int>>dp(n + 1 , vector<int>(n + 1 , -1));
    cout << f(0 , 0 , grid , dp);
    return 0;
}