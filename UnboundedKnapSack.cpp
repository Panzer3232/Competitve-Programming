#include<bits/stdc++.h>

using namespace std;
int t[102][1002];

 int max(int a, int b) { return (a > b)? a : b; } 
 int knapSack(int W,int wt[],int val[],int n){
     if(n==0||n==1)
     return 0;
     if(t[n][W]!=-1)return t[n][W];
     if(wt[n-1]>W){
         t[n][W]=knapSack(W,wt,val,n-1);
         return t[n][W];
     }
     else{
         t[n][W]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n),knapSack(W,wt,val,n-1));
         return t[n][W];
     }
 }
 int main(){
    memset(t,-1,sizeof(t));
    int W = 100; 
    int val[] = {10, 30, 20}; 
    int wt[] = {5, 10, 15}; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapSack(W, wt, val, n); 
    return 0;
 }