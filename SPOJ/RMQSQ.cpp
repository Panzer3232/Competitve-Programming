/*
You are given a list of N numbers and Q queries. Each query is specified by two numbers i and j; the answer to each query is the minimum number between the range [i, j] (inclusive).

Note: the query ranges are specified using 0-based indexing.

Input
The first line contains N, the number of integers in our list (N <= 100,000). The next line holds N numbers that are guaranteed to fit inside an integer. Following the list is a number Q (Q <= 10,000). The next Q lines each contain two numbers i and j which specify a query you must answer (0 <= i, j <= N-1).

Output
For each query, output the answer to that query on its own line in the order the queries were made.

Example
Input:
3
1 4 1
2
1 1
1 2
Output:
4
1
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
	#define INF 1000000000
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
	int st[400001] , arr[100001];

	void build(int si,int ss,int se){
	    if(ss==se){
		st[si]=arr[ss];
		return;
	    }
	    int mid=(ss+se)/2;
	    build(2*si,ss,mid);
	    build(2*si+1,mid+1,se);
	    st[si]= min(st[2*si],st[2*si+1]);
	}

	int query(int si,int ss,int se, int qs,int qe){
	    if(qs>se || qe<ss)
	    return INF;
	    if(ss>=qs && se<=qe){
		return st[si];
	    }
	    int mid=(ss+se)/2;
	    int l=query(2*si,ss,mid,qs,qe);
	    int R=query(2*si+1,mid+1,se,qs,qe);

	    return min(l,R);
	}

	int main()
	{
	    ios_base::sync_with_stdio(false);
	    cin.tie(0);
	    cout.tie(0);
		int n , q , l , r;
		cin>>n;
		for(auto i=1;i<=n;i++){
		    cin>>arr[i];
		}
		cin>>q;
		build(1 , 1 , n);
		while(q--)
		{
			cin>>l>>r;
			cout<<query(1 , 1 , n , l+1 , r+1)<<nl;
		}
	    return 0;
	}
