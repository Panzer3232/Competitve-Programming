/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/
#include <vector> 
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>ar;
        int n=nums.size();
        int numzero=0;
        for(auto i=0;i<n;i++){
            if(nums[i]==0)
                numzero++;
        }
        for(auto i=0;i<n;i++){
            if(nums[i]!=0)
                ar.push_back(nums[i]);
        }
        while(numzero--){
            ar.push_back(0);
        }
        for (int i = 0; i < n; i++) {
        nums[i] = ar[i];
    }
        
    }
};
