#include<bits/stdc++.h>
using namespace std;

int lcs(string &str1, string &str2){
    int n = str1.size() , m = str2.size();
    vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , 0));
    for(int i = n - 1 ; i >= 0 ; i --) {
        for(int j = m - 1 ; j >= 0 ; j --) {
            int match = 0 , notmatch = 0;
            if(str1[i] == str2[j]) match = 1 + dp[i + 1][j + 1];
            notmatch = 0;
            dp[i][j] = max(notmatch , match);
        }
    }
    int ans = INT_MIN;
    for(auto i : dp) {
        for(auto j : i) ans = max(ans , j);
    }
    return ans;
}

int main() {
    string str1 , str2;
    cin >> str1 >> str2;
    cout << lcs(str1 , str2) << endl;
    return 0;
}