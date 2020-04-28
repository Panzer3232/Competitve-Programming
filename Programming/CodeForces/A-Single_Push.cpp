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

bool solve(){
    ll n;
    cin>>n;
    ll extSize=n+2;
    vector<ll> orig(extSize), target(extSize);
    vector<ll> diff(extSize, 0);
    ll cnt=0;
    for(ll i=0;i<n;++i){
        cin>>orig[i];
    }
    for(ll i=0;i<n;++i){
        cin>>target[i];
        diff[i]=target[i]-orig[i];
    }
    for(ll i=0;i<extSize-1;++i){
        if(diff[i]<0){
            return false;
        }
        if(diff[i]!=diff[i+1]){
            ++cnt;
        }
    }
    return (cnt<=2);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll t;
    cin >> t;
    while(t--)
    {
       if(solve()){
           cout<<"YES"<<" ";cout<<endl;
       }
       else{
           cout<<"NO"<<" ";cout<<endl;
       }
       
}

    return 0;
}