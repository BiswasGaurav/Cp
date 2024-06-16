#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for(int i = 0 ; i < n ; i++) cin >> arr[i];
        int prev = arr[0] , ans = 0;
        for(int i = 1 ; i < n ; i++) {
            if(arr[i] >= prev) prev = arr[i];
            else {
                int j = 0;
                while((arr[i] << j) < prev) {
                    arr[i] = (arr[i] << j);
                    j ++;
                    ans ++;
                }
                prev = (arr[i] << j);
                // cout << i << " : " << prev << endl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}