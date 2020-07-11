/*
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-

Query 0:- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.

input:
First line of the input contains the number N. Next line contains N natural numbers.
Next line contains an integer Q followed by Q queries.
0 x y - modify the number at index x to y.
1 x y - count the number of even numbers in range l to r inclusive.
2 x y - count the number of odd numbers in range l to r inclusive.

Constraints:
1<=N,Q<=10^5
1<=l<=r<=N
0<=Ai<=10^9
1<=x<=N
0<=y<=10^9

Note:- indexing starts from 1.

SAMPLE INPUT 
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
SAMPLE OUTPUT 
2
2
4
Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
*/
#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
using namespace std;
const int maxN = 100001;
pair<int,int> st[4*maxN];
int val[maxN];
 
void build(int si , int ss , int se)
{
	if(ss == se)
	{
		if(val[ss] % 2 == 1)
		st[si] = {1 , 0};
		else
		st[si] = {0 , 1};
		
		return;
	}
	
	int mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si+1, mid+1 , se);
	
	st[si].first = st[2*si].ff + st[2*si+1].ff;
	st[si].second = st[2*si].ss + st[2*si+1].ss;
}
 
void update(int si , int ss , int se , int qi , int newVal)
{
	if(ss == se)
	{
		if(val[ss] % 2)
		st[si] = {0 , 1};
		else
		st[si] = {1 , 0};
		
		val[ss] = newVal;
		return;
	}
	
	int mid = (ss + se) / 2;
	if(qi <= mid) update(2*si , ss , mid , qi , newVal);
	else		  update(2*si+1 , mid+1 , se , qi , newVal);
	
	st[si].first = st[2*si].ff + st[2*si+1].ff;
	st[si].second = st[2*si].ss + st[2*si+1].ss;
}
 
int getEven(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;
	
	if(ss >= qs && se <= qe)
	return st[si].ss;
	
	int mid = (ss + se) / 2;
	
	int l = getEven(2*si , ss , mid , qs , qe);
	int r = getEven(2*si+1 , mid+1 , se , qs , qe);
	
	return l+r;
}
 
int getOdd(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;
	
	if(ss >= qs && se <= qe)
	return st[si].ff;
	
	int mid = (ss + se) / 2;
	
	int l = getOdd(2*si , ss , mid , qs , qe);
	int r = getOdd(2*si+1 , mid+1 , se , qs , qe);
	
	return l+r;
}
 
int main()
{
	int n , q , code , l , r;
	cin>>n;
	REP(i , n) cin>>val[i];
	
	build(1 , 1 , n);
	
	cin>>q;
	while(q--)
	{
		cin>>code;
		if(code == 0)
		{
			cin>>l>>r;
			if((val[l] % 2) == (r % 2)) continue;
			else update(1 , 1 , n , l , r);
		}
		else
		if(code == 1)
		{
			cin>>l>>r;
			cout<<getEven(1 , 1 , n , l , r)<<endl;
		}
		else
		{
			cin>>l>>r;
			cout<<getOdd(1 , 1 , n , l , r)<<endl;
		}
	}
}
