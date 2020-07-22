/*
Chefina has two sequences A1,A2,…,AN and B1,B2,…,BN. She views two sequences with length N as identical if, after they are sorted in non-decreasing order, the i-th element of one sequence is equal to the i-th element of the other sequence for each i (1≤i≤N).

To impress Chefina, Chef wants to make the sequences identical. He may perform the following operation zero or more times: choose two integers i and j (1≤i,j≤N) and swap Ai with Bj. The cost of each such operation is min(Ai,Bj).

You have to find the minimum total cost with which Chef can make the two sequences identical.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains N space-separated integers B1,B2,…,BN.
Output
For each test case, print a single line containing one integer ― the minimum cost, or −1 if no valid sequence of operations exists.

Constraints
1≤T≤2,000
1≤N≤2⋅105
1≤Ai,Bi≤109 for each valid i
the sum of N over all test cases does not exceed 2⋅106
Subtasks
Subtask #1 (15 points):

T≤20
N≤20
Subtask #2 (85 points): original constraints

Example Input
3
1
1
2
2
1 2
2 1
2
1 1
2 2
Example Output
-1
0
1
Explanation
Example case 1: There is no way to make the sequences identical, so the answer is −1.

Example case 2: The sequence are identical initially, so the answer is 0.

Example case 3: We can swap A1 with B2, which makes the two sequences identical, so the answer is 1.
*/


#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")
 
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define MAX 100000
#define pow2(x) ((x)*(x))
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
#define int      long long int
#define nitro    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define F        first
#define S        second
#pragma GCC optimize "trapv"
 
#define all(c) (c).begin(),(c).end()
#define nl "\n"

 
typedef vector<int> vl;
typedef vector< vl > vvl;
typedef pair<int,int> pll;
typedef map<int,int> mll;

 
using namespace std;
 
signed main()
{
 nitro;
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 int t;
 cin>>t;
 while(t--)
 {
     int n;
     cin>>n;
     vector<int> a1(n),b1(n);
     map<int, int> m1,m2,m3,m4,m5;
     
     for(int i=0;i<n;i++){
     cin>>a1[i];
     m1[a1[i]]++;
     m3[a1[i]]++;
     }
     
     for(int i=0;i<n;i++){
     cin>>b1[i];
     m2[b1[i]]++;
     m3[b1[i]]++;
     }
     
     int flag=0;
     for(auto i:m3)
     {
         if(i.S%2!=0)
         {
             flag=1;
             break;
         }
     }
     
     int arr1[n],arr2[n];
     for(int i=0;i<n;i++)
     arr1[i]=a1[i];
     for(int i=0;i<n;i++)
     arr2[i]=b1[i];
     sort(arr1,arr1+n);
     sort(arr2,arr2+n);
     int p=0;
     
     
     for(int i=0;i<n;i++)
     {
         if(arr1[i]!=arr2[i])
         {
             p=1;
             break;
         }
     }
     
     if(p==0)
     cout<<0<<endl;
     else if(flag==1)
     cout<<-1<<endl;
     
     else
     {
     	int c=0;
     	int m=INT_MAX;
     	for(int i=0;i<n;i++)
     	m=min(m,a1[i]);
     	for(int i=0;i<n;i++)
     	m=min(m,b1[i]);
        for(auto i:m1)
        {
            if(i.S>m2[i.F])
            m4[i.F]=(i.S-m2[i.F])/2;
        }
        for(auto i:m2)
        {
            if(i.S>m1[i.F])
            m5[i.F]=(i.S-m1[i.F])/2;
        }
        std::vector<int> l1,l2;
        for(auto i:m4)
        {
            for(int j=0;j<i.S;j++)
            l1.pb(i.F);
        }
        for(auto i:m5)
        {
            for(int j=0;j<i.S;j++)
            l2.pb(i.F);
        }
        sort(l1.begin(),l1.end());
        sort(l2.begin(),l2.end(),greater<int>());
        for(int i=0;i<l1.size();i++)
        {
        	int k1=l1[i];
        	int k2=l2[i];
        	c+=min(2*m,(min(k1,k2)));
        }
        cout<<c<<endl;
     }
 }
 return 0;
}
