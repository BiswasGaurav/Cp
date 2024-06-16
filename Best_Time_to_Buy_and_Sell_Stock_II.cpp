#include<bits/stdc++.h>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>ahed(2 , 0) , curr(2 , 0);
        for(int idx = prices.size() - 1 ; idx >= 0 ; idx--) {
            for(int canBuy = 0 ; canBuy <= 1 ; canBuy ++) {
                int profit = 0;
                if(canBuy) {
                    profit = max(ahed[0] - prices[idx] , ahed[1]);
                } else {
                    profit = max(ahed[1] + prices[idx] , ahed[0]);
                }
                curr[canBuy] = profit;
            }
            ahed = curr;
        }
        return curr[1];
    }
};

using namespace std;
int main() {
    return 0;
}