#include <bits/stdc++.h>
#define MOD 1000000007;

using namespace  std;
 long long int fact(long long int );
 long long int ar[100005];
 void init(){
	long long int i;
	for(i = 0; i<100005; i++)
	ar[i]=-1;
}


 long long int fact(long long int n){
     if(n==0||n==1){
         ar[0]=ar[1]=1;
         return 1;
     }
     else if(ar[n]!=-1)
     return ar[n];
     ar[n]=(n*fact(n-1))%MOD;
     return ar[n];
 }

 int main(){
     long long int t;
     init();
     cin >>t;
     while(t--){
         long long int n;
         cin>>n;
         cout<<(fact(n))%MOD;
         cout<<"\n";
     }
     return 0;
 }