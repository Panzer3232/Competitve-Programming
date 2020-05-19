/*
Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string

Input : geeksforgeeks
Output : 8
*/
#include<bits/stdc++.h>
using namespace std;

 int LCS(string X, string Y,int n,int m){
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
 int minimumNumberOfDeletions(string str){
        string s1(str);
		reverse(s1.begin(), s1.end());
		int n=str.length();
		int m=s1.length();
		int lps=LCS(str,s1,n,m);
		int min=str.length()-lps;
		return min;
}

int main() 
{ 
   string str = "geeksforgeeks"; 
    cout << "Minimum number of deletions = "
         << minimumNumberOfDeletions(str); 
    return 0;
    return 0; 
} 
