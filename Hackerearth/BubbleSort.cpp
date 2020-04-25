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
 
    ll t;
    cin >> t;
	ll a[t];
	for(ll i=0;i<t;i++){
		cin>>a[i];
	}
	ll count =0;
	ll temp;
	for(ll k=0;k<t-1;k++){
	for(ll i=0;i<t-k-1;i++){
		if(a[i]>a[i+1]){
		temp=a[i];
        a[i]=a[i+1];
        a[i+1]=temp;
         count++;
		}
	}
	}
	cout<<count<<" ";cout<<endl;

    return 0;
}