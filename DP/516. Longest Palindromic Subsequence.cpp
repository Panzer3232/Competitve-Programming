/*

Basically we can solve LPS using Longest common subsequence concept . In LCS we need a 2 string as a input and there is catch here that
if we reverse the input string and store it in another string and apply LCS on it ,this will give us LPS .

example given string a="agbcba" reversing it nd storing in another string b give us b="abcbga" and apply LCS on both strings will 
give us LPS which is ="abcba".
*/
/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
*/
class Solution {
public:
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
	int longestPalindromeSubseq(string s) {
		std::string s1(s);
		std::reverse(s1.begin(), s1.end());
		int n=s.length();
		int m=s1.length();
		int lps=LCS(s,s1,n,m);
		return lps;
	}
};
