//Leetcode Question

/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.  If multiple answers exist, you may return any of them.

(A string S is a subsequence of string T if deleting some number of characters from T (possibly 0, and the characters are chosen anywhere from T) results in the string S.)

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
 

Note:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/
class Solution {
public:
    string shortestCommonSupersequence(string X, string Y) {
     int n=X.length();
     int m=Y.length();
     string s="";
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
                 if(t[i][j-1]>t[i-1][j]){
                 s.push_back(Y[j-1]);
                 j--;
                 }
                 else{
                 s.push_back(X[i-1]) ;   
                 i--;
             }
         }
    }
        while(i>0)
        {
            s.push_back(X[i-1]);  
                 i--;
        }
        while(j>0){
             s.push_back(Y[j-1]) ;   
                 j--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
