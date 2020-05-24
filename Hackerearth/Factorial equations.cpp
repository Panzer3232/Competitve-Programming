/*
You are given two numbers  and . Your task is to find the last digit of the following equation: 

Input format

The first line contains two integers  and .

Output format

Print the last digit of the given equation.

Constraints


SAMPLE INPUT 
5 2
SAMPLE OUTPUT 
5
Explanation
factorial of (2) is 2*1=2  ,So 5^2=25 the last digit in 25 is 5

Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/
#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")
 
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define MAX 100000
#define pow2(x) ((x)*(x))
#define ll long long
#define ld long double
#define eb emplace_back
#define pb push_back
#define pf push_front
 
#define mod 1000000007
#define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
 
#define mp make_pair
#define ff first
#define ss second
#define null NULL
 
#define all(c) (c).begin(),(c).end()
#define nl "\n"
 
typedef vector<ll> vl;
typedef vector< vl > vvl;
typedef pair< ll,ll> pll;
typedef map< ll,ll> mll;

unsigned long long int multiply(unsigned long long int x, unsigned long long int res[], unsigned long long int res_size) { 
  
// Initialize carry 
unsigned long long int carry = 0; 
  
// One by one multiply n with 
// individual digits of res[] 
for (auto i = 0; i < res_size; i++) { 
    unsigned long long int prod = res[i] * x + carry; 
  
    // Store last digit of 
    // 'prod' in res[] 
    res[i] = prod % 10; 
  
    // Put rest in carry 
    carry = prod / 10; 
} 
  
// Put carry in res and 
// increase result size 
while (carry) { 
    res[res_size] = carry % 10; 
    carry = carry / 10; 
    res_size++; 
} 
return res_size; 
} 
  
// This function finds 
// power of a number x 
unsigned long long int power(unsigned long long int x, unsigned long long int n)  
{ 
  
//printing value "1" for power = 0 
if(n == 0 ){   
    return 1; 
} 
  
  
unsigned long long int res[MAX]; 
unsigned long long int res_size = 0; 
unsigned long long int temp = x; 
  
// Initialize result 
while (temp != 0) { 
    res[res_size++] = temp % 10; 
    temp = temp / 10; 
} 
  
// Multiply x n times 
// (x^n = x*x*x....n times) 
for (auto i = 2; i <= n; i++) 
    res_size = multiply(x, res, res_size); 
  
return res_size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long int num,X,N,ans;
	cin>>X>>N;
	num=pow(X,N%10);
	ans=num%10;
	cout<<ans<<" ";cout<<"\n";
    return 0;
}
