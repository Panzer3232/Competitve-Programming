#include<bits/stdc++.h>

using namespace std;


 int findCnt(int set[],int sum,int n){
     int subset[n+1][sum+1];
    for(auto i=0;i<n+1;i++){
        for(auto j=0;j<sum+1;j++){
            if(i==0)
            subset[i][j]=0;
            if(j==0)
             subset[i][j]=1;
        }
    }
    for(auto i=1;i<n+1;i++){
        for(auto j=1;j<sum+1;j++){
            if(set[i-1]<=j)
            subset[i][j]=subset[i-1][j-set[i-1]]+ subset[i-1][j];
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
    int set[] = { 3, 3, 3, 3 }; 
    int n = sizeof(set) / sizeof(int); 
    int sum= 6; 
  
    cout << findCnt(set, sum, n)<<" ";cout<<endl; 
  
    return 0; 
} 