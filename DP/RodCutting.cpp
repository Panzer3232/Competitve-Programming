    #include<bits/stdc++.h>
    
    using namespace std;
    int k[102][1002];
    
     int max(int a, int b) { return (a > b)? a : b; } 
     int rodCutting(int len[],int val[],int size,int n){
         int i,w;
          for (i = 0; i < n+1; i++) 
       { 
           for (w = 0; w < size+1; w++) 
           { 
               if (i==0 || w==0) 
                   k[i][w] = 0; 
               else if (len[i-1] <= w) 
                     k[i][w] = max(val[i-1] + k[i][w-len[i-1]],  k[i-1][w]); 
               else
                     k[i][w] = k[i-1][w]; 
           } 
       } 
             return k[n][size];
     }
     int main(){
         int n;
        cin>>n;
        int len[n];
        for(auto i=0;i<n;i++){
            cin>>len[i];
        }
         int val[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
        int size = sizeof(val)/sizeof(val[0]);
        cout << rodCutting(len,val,size,n);
        return 0;
     }