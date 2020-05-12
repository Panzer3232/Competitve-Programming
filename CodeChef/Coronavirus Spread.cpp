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
  cin>>t;
  while(t--){
      ll  i,min=INT_MAX,max=1,arr[mod],n,chain;
      cin>>n;
      for(i=0;i<n;i++){
      cin>>arr[i];
      }
      if(arr[n-1]-arr[n-2]>2){
             min=1;
         }
     for(i=0;i<n-1;i++){
         chain=1;
         while(i<n-1&& arr[i+1]-arr[i]<=2){
             i++;
             chain++;
         }
         if(chain>max)
         max=chain;
         if(chain<min)
         min=chain;
     }
      cout<<min<<" "<<max<<" ";cout<<endl;
  }
 
    return 0;
}
