/*
Input: str = "aabb"
Output: "ab"

Input: str = "aab"
Output: "a"
The two subsequence are 'a'(first) and 'a' 
(second). Note that 'b' cannot be considered 
as part of subsequence as it would be at same
index in both.
*/
#include<bits/stdc++.h>
using namespace std; 

 string LPS(string str,int n){
    string s= " ";
    int t[n+1][n+1];
    for(auto i=0;i<n+1;i++){
            for(auto j=0;j<n+1;j++){
                if (i == 0 || j == 0) 
                  t[i][j] = 0; 
                else if (str[i-1] == str[j-1] && i!=j) 
                  t[i][j] = t[i-1][j-1] + 1; 
                else
                  t[i][j] = max(t[i-1][j], t[i][j-1]); 
            }
        }
        int i=n;
        int j=n;
         while(i>0 && j>0){
             if(t[i][j]==t[i-1][j-1] +1){
                 s.push_back(str[i-1]);
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
    string str = "banana"; 
    int n=str.length();
    cout << LPS(str, n); 
    return 0; 
} 
