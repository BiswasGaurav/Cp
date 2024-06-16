#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {

    int lo = 0 , hi = 1 , n = prices.size() , maxy = 0;
    while(hi != n) {
        if(prices[hi] < prices[lo]) lo = hi;
        else maxy = max(prices[hi] - prices[lo] , maxy);
        hi ++;
    }
    return maxy;
}

int main() {
    int n;
    cin >> n;
    vector<int>arr;
    for(int i = 0 ; i < n ; i++) {
        int ele;
        cin >> ele; arr.push_back(ele);
    }
    cout << maximumProfit(arr) << endl;
    return 0;
}