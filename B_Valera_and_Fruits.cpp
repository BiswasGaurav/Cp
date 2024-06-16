#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , cap , ans = 0;
    cin >> n >> cap;
    map<int,int>mp;
    for(int i = 0 ; i < n ; i++) {
        int a , b;
        cin >> a >> b;
        mp[a] += b;
    }
    
    return 0;
}