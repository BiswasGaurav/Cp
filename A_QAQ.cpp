#include<bits/stdc++.h>
using namespace std;
int f(int i , int j , string &a , string &b , vector<vector<int>>&dp) {
    if(j < 0) return 1;
    if(i < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(a[i] == b[j]) return dp[i][j] = f(i - 1 , j , a , b , dp) + f(i - 1 , j - 1 , a , b , dp);
    else dp[i][j] = f(i - 1 , j , a , b , dp);
}
int main() {
    string s , t;
    cin >> s;
    t = "QAQ";
    int n = s.size() , m = t.size();
    vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , -1));
    cout << f(n - 1 , m - 1 , s , t , dp) << endl;
    return 0;
}