#include<bits/stdc++.h>
using namespace std;
const int MOD;

int power(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
    int temp = power(a,b/2);
    int result = temp*temp;
    if(b%2==1) result*=a;
    return result;  
}

//--------------------Copied---------------------------//
int a,b;
 
//O(r)
int nCr(int n, int r) {
    int sum=1;
     for(int i = 1; i <= r; i++){
            sum = sum * (n - r + i) / i;
        }
    return sum;
}
//O(log(min(a,b)))
int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}   
//O(log(min(a,b)))
int lcm(int a, int b){
    return (a / gcd(a , b)) * b;
}
 
//MEX
int MEX(vector<int>&v){
    map<int,int>mp;
    for(int i = 0 ; i < v.size() ; i++) {
        mp[v[i]]++;
    }
    map <int,int> ::iterator it;
    int cnt = 0;
    int ans = v.size();
    for(it = mp.begin() ; it != mp.end() ; it++){
        if(it->first != cnt){
            ans = cnt;
            break;
        }
        cnt++;
        ans = cnt;
    }
    return ans;
}
 
//O(n)
//Maximum sum of subarray in array of length n
int maxSubArraySum(int a[], int n)
{
    int max_so_far = INT_MIN, max_ending_here = 0;
 
    for (int i = 0; i < n; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
 
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
 
bool isPowerOfTwo(unsigned int n){
return (n&&!(n&n-1));
}

void prime(int n){
    for(int i=0;i*i<n;i++){
        while(n%i == 0)
        {
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>1) cout<<n<<" ";
}
 
bool is_prime(int n){
    if(n==1)
    return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
        return false;
    }
    return true;
}
 
 
int power(int a,int b){
    if(b==0) return 1;
    int tmp=power(a,b/2);
    int result=((tmp % MOD) * (tmp % MOD)) % MOD;
    if(b%2==1) result =((result % MOD) * (a % MOD)) % MOD;
    return result;
}
 
int Binexpitr(int a,int b,int m){
    int ans=1;
    while(b){
        if(b&1){ans = (ans* 1ll *a)%m;}
        a=(a*1ll*a)%m;b>>=1;}
    return ans;}
int modinv(int n,int m){
    return Binexpitr(n,m-2,m);}
    
int mod_add(int a,int b, int m){
    a=a%m; b=b%m; 
    return (((a+b)%m)+m)%m;
}
int mod_mul(int a, int b, int m){
    a=a%m;b=b%m;
    return (((a*b)%m)+m)%m;
}
int mod_sub(int a,int b,int m){
    a=a%m;b=b%m;
    return (((a-b)%m)+m)%m;
}
//only for prime m
int mod_div(int a,int b,int m){ 
    a=a%m;b=b%m;
    return (mod_mul(a,modinv(b,m),m)+m)%m;
}
 
//binary to decimal
int binaryToDecimal(int n)
{
    int dec_num = 0 , power = 0 ;
        while(n>0){
        if(n%10 == 1)
        dec_num += (1<<power);
        power++ ; 
        n = n / 10 ;
    }
    return dec_num ;
}
 
//decimal to binary
string decimalToBinary(int n)
{
    string s = bitset<64> (n).to_string();
    const auto loc1 = s.find('1');
    if(loc1 != string::npos)
    return s.substr(loc1);
    return "0";
}
 
 
//___________________________________________________________________//
 
//FOR DEBUGGING
#define printarr(arr) for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){ cout << arr[i] << " ";}cout << endl;
#define printvec(v) for(int i=0;i<v.size();i++){ cout << v[i] << " ";}cout << endl;
#define printset(s) for(auto i : s){cout << i << " ";}cout<<endl;
#define printmap(m) for(auto i : m){cout<<i.first<<" "<<i.second<<" ";cout<<endl;}
#define outvecpair(v) for(int i=0;i<v.size();i++){cout << v[i].first << " " << v[i].second << endl;}
 
//____________________________________________________________________//
//--------------------Copied---------------------------//







//<-----------------Primes-start------------------>//
/*
If a number is even it can represented as the sum of two prime numbers and
if it is odd then it can be represented as the sum of two prime numbers if
n-2 is prime...but if n-2 is not prime then it would take atleast 3 prime
numbers to accumulate the total sum to that number.
*/

bool checkPrime(int n)
{
    int counter = 0;
    for(int i = 1 ; i*i <= n ; i++)
    {
        if(n % i == 0)
        {
            counter ++;
            if(n/i != i) counter ++;
        }
    }
    return (counter == 2);
}

int highestFactor(int n)
{
    int factor = 1;
    for(int i = 1 ; i <= n ; i++) 
    {
        if(n % i == 0) factor = i;
    }
    return factor;
}

const int N = 1e6;
bool sieve[N + 1];
void Createsieve()
{
    for(int i = 2 ; i <= N ; i++) sieve[i] = true;

    for(int i = 2 ; i * i <= N ; i++)
    {
        if(sieve[i])
        {
            for(int j = i*i ; j <= N ; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

//<-----------------Primes-end------------------>//

//<------------------Bit-wise------------------->//

int totalXor(int n)
{
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    else return 0;
}

bool powerOf2(int n)
{
    bool bit = !(n & (n - 1));
    return n && bit;
}

void powerSet(int arr[] , int n)
{
    vector<int>subset;
    for(int number = 0 ; number < (1 << n) ; number ++)
    {
        for(int bit = 0 ; bit < n ; bit++)
        {
            if(number & (1 << bit)) subset.push_back(arr[bit]);
        }
        for(auto i : subset) cout << i << " ";
        cout << endl;
        subset.clear();
    }
    return ;
}

//<------------------Bit-wise------------------->//
int main()
{
    // cout << sieve[23] << " " << sieve[16] << endl;
    return 0;
}