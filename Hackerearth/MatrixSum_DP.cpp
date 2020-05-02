#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, y;
    long q;
    cin>>n>>m;
    long arr[n+1][m+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
            if(i==1 && j!=1) arr[i][j]+= arr[i][j-1];
            else if(j==1 && i!=1) arr[i][j]+= arr[i-1][j];
            else if(i!= 1 && j!=1){
                arr[i][j]= arr[i][j]+ arr[i-1][j]+ arr[i][j-1]- arr[i-1][j-1];}  
        }
    }
    
    cin>>q;
    while(q--){
        cin>>x>>y;
        cout<<arr[x][y]<<endl;
    }
    return 0;
}