#include<bits/stdc++.h>
using namespace std;

int f(int idx , vector<vector<int>>&cost , vector<bool>&visited) {
    if(idx == cost.size()) return 0;
    int m = cost.size() , n = cost[0].size() , temp = 1e9;
    for(int col = 0 ; col < m ; col ++) {
        for(int row = 0 ; row < n ; row ++) {
            if(!visited[row]) {
                visited[row] = true;
                int take = cost[col][row] + f(idx + 1 , cost , visited);
                visited[row] = false;
                int notTake = 0 + f(idx + 1 , cost , visited);
                return min(take , notTake);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>>cost(n , vector<int>(n));
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) cin >> cost[i][j];
    }
    vector<bool>visited(n , false);
    cout << f(0 , cost , visited) << endl;
    return 0;
}