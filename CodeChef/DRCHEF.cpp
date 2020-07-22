/*
Chef is multi-talented. He has developed a cure for coronavirus called COVAC-19. Now that everyone in the world is infected, it is time to distribute it throughout the world efficiently to wipe out coronavirus from the Earth. Chef just cooks the cure, you are his distribution manager.

In the world, there are N countries (numbered 1 through N) with populations a1,a2,…,aN. Each cure can be used to cure one infected person once. Due to lockdown rules, you may only deliver cures to one country per day, but you may choose that country arbitrarily and independently on each day. Days are numbered by positive integers. On day 1, Chef has x cures ready. On each subsequent day, Chef can supply twice the number of cures that were delivered (i.e. people that were cured) on the previous day. Chef cannot supply leftovers from the previous or any earlier day, as the cures expire in a day. The number of cures delivered to some country on some day cannot exceed the number of infected people it currently has, either.

However, coronavirus is not giving up so easily. It can infect a cured person that comes in contact with an infected person again ― formally, it means that the number of infected people in a country doubles at the end of each day, i.e. after the cures for this day are used (obviously up to the population of that country).

Find the minimum number of days needed to make the world corona-free.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and x.
The second line contains N space-separated integers a1,a2,…,aN.
Output
For each test case, print a single line containing one integer ― the minimum number of days.

Constraints
1≤T≤103
1≤N≤105
1≤ai≤109 for each valid i
1≤x≤109
the sum of N over all test cases does not exceed 106
Subtasks
Subtask #1 (20 points): a1=a2=…=aN
Subtask #2 (80 points): original constraints

Example Input
3
5 5
1 2 3 4 5
5 1
40 30 20 10 50
3 10
20 1 110
Example Output
5
9
6
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
    #define int      long long int
    #define nitro    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    #define DEBUG    falss
    #pragma GCC optimize "trapv"
     
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

 
using namespace std;
 
int32_t main()
{
 nitro;
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 int t;
 cin>>t;
 while(t--)
 {
    int n,x;
    cin>>n>>x;
    vector<int> v1(n);
    
    for(auto i=0;i<n;i++){
        cin>>v1[i];
    }
    
    
    sort(v1.begin(),v1.end());
    
    vector<int>::iterator it = lower_bound(v1.begin(), v1.end(), x);
    
    int lowerBound = it - v1.begin();
    
    int s=0;
    
    
    for(int i=lowerBound;i<n;i++)
    {
    	if(x<v1[i])
    	{
    		while(x<v1[i])
    		{
    			x=2*x;
    			s++;
    		}
    		s++;
    	}
    	else
    	s++;
    	x=2*v1[i];
    }
    
    
    int total=lowerBound+s;
    if(lowerBound!=0)
    {
    	s=0;
    	lowerBound--;
    	for(int i=lowerBound;i<n;i++)
    	{
    		if(x<v1[i])
    		{
    			while(x<v1[i])
    			{
    				x=2*x;
    				s++;
    			}
    			s++;
    		}
    		else
    		s++;
    		x=2*v1[i];
    	}
    	int answer=min(s+lowerBound,total);
    	cout<<answer<<endl;
    }
    
    
    else
    cout<<total<<endl;
    
 }
 return 0;
}

