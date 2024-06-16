#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int>dp(n + 1 , 1e9);
    dp[0] = 0;
    for(int i = 1 ; i <= n ; i++) {
        string num = to_string(i);
        for(char digit : num) {
            int x = digit - '0';
            if(x) dp[i] = min(dp[i] , dp[i - x] + 1);
        }
    }
    cout << dp[n] << endl;
}