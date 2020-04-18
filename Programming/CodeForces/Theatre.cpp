/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
   long long int n,m,a,l,w;
   cin>>n>>m>>a;
   l=n/a;
   w=m/a;
  if(n%a!=0)l++;
  if(m%a!=0)w++;
  cout<<l*w<<endl;

    return 0;
}

