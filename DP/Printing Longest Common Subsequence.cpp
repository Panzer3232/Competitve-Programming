/*
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4
*/
#include<bits/stdc++.h>
using namespace std; 

 string LCS(string X, string Y,int n,int m){
    string s= " ";
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
        int i=n;
        int j=m;
         while(i>0 && j>0){
             if(X[i-1]==Y[j-1]){
                 s.push_back(X[i-1]);
                 i--;
                 j--;
             }
             else{
                 if(t[i][j-1]>t[i-1][j])
                 j--;
                 else
                 i--;
             }
         }
         reverse(s.begin(),s.end());
        return s;
}

int main() 
{ 
    string X = "AGGTAB"; 
   string Y =  "GXTXAYB"; 
    int n =   X.length() ; 
    int m =   Y.length(); 
    cout << "LCS of " << X << " and " << Y << " is " << LCS(X, Y, n, m); 
    return 0; 
} 
