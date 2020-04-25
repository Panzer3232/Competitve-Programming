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
 
 ll expoMod(ll A,ll B,ll M){ 
  if(B==0) return 1LL;
if(B%2==0) return expoMod((A*A)%M , B/2, M);
else return ( A* (expoMod( (A*A)%M , B/2, M ) ))%M;

}
    ll d,x,y;
  void extendEuclid(ll C,ll M){
		if(M==0){
			d=C;
			x=1;y=0;
		}
		else{
			extendEuclid(M,C%M);
			ll temp =x;
			x=y;
			y=temp-(C/M)*y;
		}
	}

 ll inverseMod(ll C,ll M ){
	extendEuclid(C,M);
	return (x%M+M)%M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll A,B,C,M;
	cin>>A>>B>>C>>M;
	ll ans1= expoMod(A,B,M);
	ll ans2=inverseMod(C,M);
	ll ans=(ans1*ans2)%M;
	cout<<ans<<" ";cout<<endl;

    return 0;
}