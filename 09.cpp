#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int f(int n , int m , vector< vector< int> > &mat , vector<vector<int>>&dp) {
    if(n == 0 and m == 0) return 1;
    if(n < 0 || m < 0 || mat[n][m] == -1) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    int left = f(n - 1 , m , mat , dp);
    int up = f(n , m - 1 , mat , dp);
    return dp[n][m] = (left % MOD + up % MOD) % MOD;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n + 10 , vector<int>(m + 10 , -1));
    return f(n - 1 , m - 1 , mat , dp);
}

int main() {

    return 0;
}