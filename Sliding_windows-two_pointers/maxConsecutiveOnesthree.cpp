/*problem (LeetCode 1004 / Striver Sheet):                                                                                                                                       
  │ Given a binary array nums (containing only 0s and 1s) and an integer k, 
    return the maximum number of consecutive 1s in the array if you can flip at most k zeros to ones.      
  │                                                                                                                                                                                
  │ Example:                                                                                                                                                                       
  │ nums = [1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0], k = 2                                                                                                                                
  │ Output: 6                                                                                                                                                                      
  │ (Explanation: Flipping the 0s at indices 4 and 5 gives [1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0], 
   having 6 consecutive ones from index 3 to 8).*/
   
#include<iostream>
#include<bits/stdc++.h>


using namespace std;


class Solution{
    public:
    int maxones(vector<int>& nums, int k){
        int n= nums.size();
        int left = 0;
        int zero_count =0;

        int maxlength =0;

        for(int right = 0;right< n; right++){
            if(nums[right] == 0){
                zero_count++;
            }

            while(zero_count > k){
                 if(nums[left] == 0){
                    zero_count--;
                 }
                 left++;
            }
            maxlength =max(maxlength,right-left+1);
        }
        return maxlength;
    }
};