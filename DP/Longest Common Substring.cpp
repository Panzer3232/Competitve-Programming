#include<bits/stdc++.h>
using namespace std; 
int min(int a, int b) { return (a < b)? a : b; }
int LCSubStr(string X, string Y,int n,int m){
    int t[n+1][m+1];
    int result=0;
    for(auto i=0;i<n+1;i++){
            for(auto j=0;j<m+1;j++){
                if(i==0)
                    t[i][j]=0;
                 if(j==0)
                    t[i][j]=0;
            }
        }
         for(auto i=1;i<n+1;i++){
        for(auto j=1;j<m+1;j++){
          if(X[i-1]==Y[j-1]){
              t[i][j]=1+t[i-1][j-1];
              result = max(result,t[i][j]);
          }
            else
                t[i][j]=0;
        }
    }
        return result;
}

int main() 
{ 
    string X = "OldSite:GeeksforGeeks.org"; 
   string Y = "NewSite:GeeksQuiz.com"; 
  
    int n =X.length() ; 
    int m = Y.length(); 
  
    cout << "Length of Longest Common Substring is " 
         << LCSubStr(X, Y, n, m); 
    return 0; 
} 
