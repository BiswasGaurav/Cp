#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int idx1 , int idx2 , string text1 , string text2 , vector<vector<int>>&dp) {
        if(idx1 == text1.size() || idx2 == text2.size()) {
            return 0;
        }
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        int a = 0 , b = 0 , c = 0;
        if(text1[idx1] != text2[idx2]) {
            a = f(idx1 + 1 , idx2 , text1 , text2 , dp);
            b = f(idx1 , idx2 + 1 , text1 , text2 , dp);
        } else {
            c = 1 + f(idx1 + 1 , idx2 + 1 , text1 , text2 , dp);
        }
        return dp[idx1][idx2] = max({a , b , c});
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() , m = text2.size();
        vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , -1));
        return f(0 , 0 , text1 , text2 , dp);
    }
};
int main() {
    string a , b;
    cin >> a >> b;
    cout << Solution().longestCommonSubsequence(a , b);
    return 0;
}