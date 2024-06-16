//Code by Cakee(Gaurav Biswas)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree< T , null_type , less<T> , rb_tree_tag , tree_order_statistics_node_update >; 
// *st.find_by_order(i) --> element at ith position
// st.order_of_key(x) --> no. of ele less than x
//For multiset change less to less_equal and for reverse order change less to greater
#define int long long 
#define endl '\n'
#define in(arr) for(auto &i : arr) cin >>i;
#define out(x) for(auto it : x){ cout<<it<<' ';} cout<<endl;
#define all(x) (x).begin(), (x).end()
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for(auto &it : v)cin >> it;return istream;}
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c){for(auto &it : c)cout << it << " ";return ostream;}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while(t--) {
        
    }
    return 0;
}