/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/
class Solution {
public:
    string LCS(string s1,string s2){
        string res="";
        int n=s1.length();
        int m=s2.length();
        for(auto i=0,j=0;i<n &&j<m;i++,j++){
                if(s1[i]!=s2[j])
                    break;
                    res.push_back(s1[i]);
            }
        return res;
    }
    string longestCommonPrefix(vector<string>& s) {
        if(s.empty()){
          string prefix="";
            return prefix;
        }
        int n=s.size();
        string prefix =s[0];
        for(auto i=1;i<n;i++){
            prefix=LCS(prefix,s[i]);
        }
        return prefix;
    }
};
