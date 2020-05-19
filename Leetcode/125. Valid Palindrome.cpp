/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int h=s.length();
        for (int i = 0; i < h; i++) 
        s[i] = tolower(s[i]);
        while(l<=h){
            if(!(s[l]>='a' && s[l]<='z') && !isalnum(s[l]))
                l++;
            else if(!(s[h]>='a' && s[h]<='z') && !isalnum(s[h]))
                h--;
            else if (s[l] ==s[h]) 
            l++, h--; 
            else 
                return false;
        }
        return true;
    }
};
