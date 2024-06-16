#include<bits/stdc++.h>
using namespace std;
#define int long long

void Complimentary_Xor(string a , string b , int n) {
    int isEqual = (a[0] == b[0]);
    for(int i = 0 ; i < n ; i++) {
        if(a[i] == b[i] != isEqual) {
            cout << "NO" << endl;
            return;
        } 
    }
    vector<pair<int,int>>ans;
    for(int i = 0 ; i < n ; i++) {
        if(a[i] == '1') {
            ans.push_back({i + 1 , i + 1});
            isEqual ^= 1;
        }
    }
    if(!isEqual) {
        ans.push_back({1 , 1});
        ans.push_back({2 , n});
        ans.push_back({1 , n});
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(auto i : ans) cout << i.first << " " << i.second << endl;
}
signed main() {
    int t;
    cin >> t;
    while(t --) {
        int n;
        cin >> n;
        string a , b;
        cin >> a >> b;
        Complimentary_Xor(a , b , n);
    }
    return 0;
}