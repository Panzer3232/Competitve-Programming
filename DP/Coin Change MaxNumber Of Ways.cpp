#include<bits/stdc++.h>

using namespace std;


 int count(int arr[],int n,int sum){
     int coin[n+1][sum+1];
    for(auto i=0;i<n+1;i++){
        for(auto j=0;j<sum+1;j++){
            if(i==0)
            coin[i][j]=0;
            if(j==0)
             coin[i][j]=1;
        }
    }
    for(auto i=1;i<n+1;i++){
        for(auto j=1;j<sum+1;j++){
            if(arr[i-1]<=j)
            coin[i][j]=coin[i][j-arr[i-1]]+ coin[i-1][j];
            else
            coin[i][j]=coin[i-1][j];
        }
    }
    return coin[n][sum];
 }
 int main() 
{ 
    int p;
    cin>>p;
     int arr[p];
     for(auto i=0;i<p;i++){
         cin>>arr[i];
     }
     int n = sizeof(arr)/sizeof(arr[0]); 
     int sum;
     cin>>sum;
    cout << count(arr, n, sum); 
    return 0; 
} 