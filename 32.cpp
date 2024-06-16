#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int f(int i , int j , string &a , string &b , vector<vector<int>>&dp) {
    if(j < 0) return 1;
    if(i < 0) return 0;
    if(dp[i][j] != -1) return (dp[i][j] % MOD);
    if(a[i] == b[j]) return dp[i][j] = (f(i - 1 , j , a , b , dp) % MOD + f(i - 1 , j - 1 , a , b , dp) % MOD) % MOD;
    else dp[i][j] = f(i - 1 , j , a , b , dp) % MOD;
}

int distinctSubsequences(string &str, string &sub)
{
	int n = str.size() , m = sub.size();
    vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , -1));
    return f(n - 1 , m  - 1 , str , sub , dp);
}

int main() {
    string a , b;
    cin >> a >> b;
    cout << distinctSubsequences(a , b) << endl;
    return 0;
}