#include<bits/stdc++.h>
using namespace std;
//There is something wromg with this code something minor --->
int f(int row , int col , vector<vector<int>>&mat , vector<vector<int>>&dp) {
    if(col == 0) return mat[col][row];
    if(row < 0 || row >= mat[0].size() - 1) return -1e8;
    if(dp[col][row] != -1) return dp[col][row];
    int up = mat[col][row] + f(row , col - 1 , mat , dp);
    int ld = mat[col][row] + f(row - 1 , col - 1 , mat , dp);
    int rd = mat[col][row] + f(row + 1 , col - 1 , mat , dp);
    return dp[col][row] =  max({up , ld , rd});
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int row = matrix[0].size() , col = matrix.size();
    vector<vector<int>>dp(col + 5 , vector<int>(row + 5 , -1));
    int maxy = INT_MIN;
    for(int i = 0 ; i < row ; i++) {
        maxy = max(maxy , f(i , col - 1 , matrix , dp));
    }
    return maxy;
}

int main() {

    return 0;
}