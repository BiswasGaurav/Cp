#include<bits/stdc++.h>
using namespace std;

int f(int i , int j , const string &str , const string &rev , vector<vector<int>>&dp) {
    if(i == str.size() || j == rev.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int match = 0 , notmatch = 0;
    if(str[i] == rev[j]) {
        match = 1 + f(i + 1 , j + 1 , str , rev , dp);
    }
    notmatch = max(f(i + 1 , j , str , rev , dp) , f(i , j + 1 , str , rev , dp));
    return dp[i][j] = max(match , notmatch);
}

int minimumInsertions(string &str)
{
	string rev = str;
    reverse(rev.begin() , rev.end());
    // vector<vector<int>>dp(str.size() + 1 , vector<int>(str.size() + 1 , -1));
    // return str.size() - f(0 , 0 , str , rev , dp);
    vector<vector<int>>dp(str.size() + 1 , vector<int>(str.size() + 1 , 0));
    for(int i = str.size() - 1 ; i >= 0 ; i --) {
        for(int j = str.size() - 1 ; j >= 0 ; j --) {
            int match = 0 , notmatch = 0;
            if(str[i] == rev[j]) {
                match = 1 + dp[i + 1][j + 1];
            }
            notmatch = max(dp[i + 1][j] , dp[i][j + 1]);
            dp[i][j] = max(match , notmatch);
        }
    }
    return str.size() - dp[0][0];
}

int main() {
    string s;
    cin >> s;
    cout << minimumInsertions(s) << endl;
    return 0;
}