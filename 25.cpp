#include<bits/stdc++.h>
using namespace std;

int f(int idx1 , int idx2 , string s , string t , vector<vector<int>>&dp) {
    if(idx1 == s.size() || idx2 == t.size()) return 0;
    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
    int match = 0 , notmatch = 0;
    if(s[idx1] == t[idx2]) match = 1 + f(idx1 + 1 , idx2 + 1 , s , t , dp);
    notmatch = max(f(idx1 + 1 , idx2 , s , t , dp) , f(idx1 , idx2 + 1 , s , t , dp));
    return dp[idx1][idx2] = max(notmatch , match);
}

int lcs(string s, string t)
{
	int n = s.size() , m = t.size();
    // vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , -1));
    // return f(0 , 0 , s , t , dp);
    vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , 0));
    for(int i = n - 1 ; i >= 0 ; i --) {
        for(int j = m - 1 ; j >= 0 ; j --) {
            int match = 0 , notmatch = 0;
            if(s[i] == t[j]) match = 1 + dp[i + 1][j + 1];
            notmatch = max(dp[i + 1][j] , dp[i][j + 1]);
            dp[i][j] = max(notmatch , match);
        }
    }
    int row = 0 , col = 0;
    // for(int i = 0 ; i < m ; i++) {
        
    // }
    return dp[0][0];
}

int main() {
    string s , t;
    cin >> s >> t;
    cout << lcs(s , t) << endl;
    return 0;
}