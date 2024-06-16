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

int canYouMake(string &s1, string &s2){
    vector<vector<int>>dp(s1.size() + 1 , vector<int>(s2.size() + 1 , 0));
    for(int i = s1.size() - 1 ; i >= 0 ; i --) {
        for(int j = s2.size() - 1 ; j >= 0 ; j --) {
            int match = 0 , notmatch = 0;
            if(s1[i] == s2[j]) {
                match = 1 + dp[i + 1][j + 1];
            }
            notmatch = max(dp[i + 1][j] , dp[i][j + 1]);
            dp[i][j] = max(match , notmatch);
        }
    }
    return s1.size() + s2.size() - (2 * dp[0][0]);
}

int main() {
    string s , t;
    cin >> s >> t;
    cout << canYouMake(s , t) << endl;
    return 0;
}