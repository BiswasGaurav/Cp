#include<bits/stdc++.h>
using namespace std;

int f(int i , int j , string &s , string &t , vector<vector<int>>&dp) {
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i] == t[j]) return dp[i][j] = 0 + f(i - 1 , j - 1 , s , t , dp);
    int rep = 1 + f(i - 1 , j - 1 , s , t , dp);
    int del = 1 + f(i - 1 , j , s , t , dp);
    int ins = 1 + f(i , j - 1 , s , t , dp);
    return dp[i][j] = min({rep , del , ins});
}

int editDistance(string str1, string str2)
{
    int n = str1.size() , m = str2.size();
    vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , -1));
    return f(n - 1 , m - 1 , str1 , str2 , dp);
}

int main() {
    string s , t;
    cin >> s >> t;
    cout << editDistance(s , t) << endl;
    return 0;
}