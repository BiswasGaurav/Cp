#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n , m;
    cin >> n >> m;
    vector<int>arr(n + 1 , 0);
    for(int i = 1 ; i <= n ; i++) {
        int ele;
        cin >> ele;
        arr[i] = (ele % m);
    }
    if(n >= m) cout << "YES" << endl;
    else {
        vector<vector<int>>dp(n + 1 , vector<int>(m + 1 , 0));
        for(int i = 1 ; i <= n ; i++) dp[i][arr[i]] = 1;
        for(int i = 2 ; i <= n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                if(dp[i][j]) continue;
                if(dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                dp[i][j] = dp[i - 1][(j - arr[i] + m) % m];
            }
        }
        if(dp[n][0]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}