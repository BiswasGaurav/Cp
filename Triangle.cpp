#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int row , int col , vector<vector<int>>&mat , vector<vector<int>>&dp) {
        if(col == mat.size() - 1) return mat[col][row];
        if(dp[col][row] != -1) return dp[col][row];
        int down = mat[col][row] + f(row , col + 1 , mat , dp);
        int diagonal = mat[col][row] + f(row + 1 , col + 1 , mat , dp);
        return dp[col][row] = min(down , diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle[triangle.size() - 1].size() , col = triangle.size();
        vector<vector<int>>dp(col + 1 , vector<int>(row + 1 , -1));
        return f(0 , 0 , triangle ,dp);
    }
};
int main() {

    return 0;
}