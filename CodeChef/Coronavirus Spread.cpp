/*There are N people on a street (numbered 1 through N). For simplicity, we'll view them as points on a line. For each valid i, the position of the i-th person is Xi.

It turns out that exactly one of these people is infected with the virus COVID-19, but we do not know which one. The virus will spread from an infected person to a non-infected person whenever the distance between them is at most 2. If we wait long enough, a specific set of people (depending on the person that was infected initially) will become infected; let's call the size of this set the final number of infected people.

Your task is to find the smallest and largest value of the final number of infected people, i.e. this number in the best and in the worst possible scenario.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-seperated integers X1,X2,…,XN.
Output
For each test case, print a single line containing two space-separated integers ― the minimum and maximum possible final number of infected people.

Constraints
1≤T≤2,000
2≤N≤8
0≤Xi≤10 for each valid i
X1<X2<…<XN
Subtasks
Subtask #1 (10 points): N≤3
Subtask #2 (90 points): original constraints

Example Input
3
2
3 6
3
1 3 5
5
1 2 5 6 7
Example Output
1 1
3 3
2 3
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
