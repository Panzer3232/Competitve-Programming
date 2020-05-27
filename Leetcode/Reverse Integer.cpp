/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2 pow 31,  2 pow 31 − 1].
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
class Solution {
public:
    int reverse(int x) {
        long long int currNum=0,revNum=0;
        while(x!=0){
            currNum = x%10;
             x=x/10;
            if((revNum >INT_MAX/10) || (revNum == INT_MAX && currNum >7)) return 0;
            if((revNum <INT_MIN/10) || (revNum == INT_MIN && currNum <-8)) return 0;  
             revNum=revNum *10+currNum;
        }
        return revNum; 
    }
};
