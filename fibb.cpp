#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7 , sizu = 1e5 + 10; 
vector<int>dp(sizu , -1);
int fibonacciNumber(int n){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] =  (fibonacciNumber(n - 1) % MOD + fibonacciNumber(n - 2) % MOD) % MOD;
}
int main() {
    int n;
    cin >> n;
    cout << fibonacciNumber(n) << endl;
    return 0;
}