#include<bits/stdc++.h>

using namespace std;


 bool isSubsetSum(int set[],int n,int sum){
     bool subset[n+1][sum+1];
    for(auto i=0;i<n+1;i++){
        for(auto j=0;j<sum+1;j++){
            if(i==0)
            subset[i][j]=false;
            if(j==0)
             subset[i][j]=true;
        }
    }
    for(auto i=1;i<n+1;i++){
        for(auto j=1;j<sum+1;j++){
            if(set[i-1]<=j)
            subset[i][j]=subset[i-1][j-set[i-1]] || subset[i-1][j];
            else
            subset[i][j]=subset[i-1][j];
        }
    }
     // uncomment this code to print table 
     for (int i = 0; i < n + 1; i++) 
     { 
       for (int j = 0; j < sum + 1; j++) 
     cout<<subset[i][j]<<" ";cout<<endl;
     }
    return subset[n][sum];
 }
 int main() 
{ 
  int set[] = {3, 34, 4, 12, 5, 2}; 
  int sum = 9; 
  int n = sizeof(set)/sizeof(set[0]); 
  if (isSubsetSum(set, n, sum) == true) 
     cout<<"Subset Found"<<endl;
  else
    cout<<"No subset with given sum"<<endl; 
  return 0; 
} 