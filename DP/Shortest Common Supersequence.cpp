/*
Input:   str1 = "geek",  str2 = "eke"
Output: "geeke"

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  "AGXGTXAYB"
*/
#include<bits/stdc++.h>
using namespace std; 

 int ShortestCommonSubs(string X, string Y,int n,int m){
    int t[n+1][m+1];
    for(auto i=0;i<n+1;i++){
            for(auto j=0;j<m+1;j++){
                if (i == 0 || j == 0) 
                  t[i][j] = 0; 
                else if (X[i-1] == Y[j-1]) 
                  t[i][j] = t[i-1][j-1] + 1; 
                else
                  t[i][j] = max(t[i-1][j], t[i][j-1]); 
            }
        }
         return t[n][m];
}

int main() 
{ 
    string X = "geek"; 
   string Y =  "eke"; 
    int n =   X.length() ; 
    int m =   Y.length(); 
    int scs = (n+m) - ShortestCommonSubs(X,Y,n,m);
    cout<<scs<<endl;
    return 0; 
} 
