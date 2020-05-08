#include<bits/stdc++.h>

using namespace std;


 int findMin(int set[],int n){
     int sum=0;
     for(auto i=0;i<n;i++){
     sum+=set[i];
     }
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
            subset[i][j]=subset[i-1][j-set[i-1]] ||subset[i-1][j];
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
     int diff=INT_MAX;
     for(auto i=sum/2;i>=0;i--){
         if(subset[n][i]==true)
         diff=sum-2*i;
         break;
     }
    return diff;
 }
int main() 
{ 
    int set[] = {3, 1, 4, 2, 2, 1}; 
    int n = sizeof(set)/sizeof(set[0]); 
    cout << "The minimum difference between 2 sets is "
         << findMin(set, n); 
    return 0; 
} 