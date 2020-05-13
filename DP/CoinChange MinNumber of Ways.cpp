#include<bits/stdc++.h>

using namespace std;

int min(int a, int b) { return (a < b)? a : b; } 
 int count(int arr[],int n,int sum){
     int coin[n+1][sum+1];
    for(auto i=0;i<n+1;i++){
        for(auto j=0;j<sum+1;j++){
            if(i==0)
            coin[i][j]=INT_MAX-1;
            if(j==0)
             coin[i][j]=0;
        }
    }
    for(auto j=1;j<sum+1;j++){
        int i=1;
        if(j%arr[0]==0)
        coin[i][j]=j%arr[0];
        else
        coin[i][j]=INT_MAX-1;
    }
    for(auto i=2;i<n+1;i++){
        for(auto j=1;j<sum+1;j++){
            if(arr[i-1]<=j)
            coin[i][j]=min(coin[i][j-arr[i-1]]+1,coin[i-1][j]);
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