/*
You are given an N-sided regular polygon. You have connected the center of the polygon with all the vertices, thus dividing the polygon into N equal parts.

Your task is to find the count of simple cycles that exist in the modified structure of the polygon.

Input format

The first line contains an integer  denoting the number of queries.
The second line contains an integer  denoting the number of sides in the regular polygon.
Output format

Print the count of simple cycles corresponding to each query in a separate line.

Constraints
 1<=N<=10 power 9
 1<=Q<=10 power 5

SAMPLE INPUT 
2
3
4
SAMPLE OUTPUT 
7
13
Explanation
No Explanation Provided

Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
BEST SUBMISSION
*/
#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")
 
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
 
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
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll N;
    cin >> N;
    while(N--)
    {
     ll Q;
	 cin>>Q;
	 ll cycle;
	 cycle=(Q*(Q-1))+1;
	 cout<<cycle<<" ";cout<<endl;
}

    return 0;
}
