/*Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book, and an integer m 
representing the number of students, allocate all the books to the students so that each student gets at least one book, 
each book is allocated to only one student, and the allocation is contiguous.

Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized.
If the allocation of books is not possible, return -1.

Example 1:
Input: nums = [12, 34, 67, 90], m=2

Output: 113

Explanation: The allocation of books will be 12, 34, 67 | 90. One student will get the first 3 books and 
the other will get the last one.

Example 2:
Input: nums = [25, 46, 28, 49, 24], m=4

Output: 71

Explanation: The allocation of books will be 25, 46 | 28 | 49 | 24.*/



#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution{
    public:
    bool ispossible(vector<int>& nums, int m, long long int mid){
        long long int s_count = 1;
        long long   int current_book= 0;
        for(int p : nums){
            if(current_book + p <= mid){
                current_book+=p;
            }
            else{
            s_count++;   
            current_book = p;
            }
        }
       
        if(s_count<= m){
            return true;
        }
        return false;

    }
    int findPages(vector<int> &nums, int m)  {
        if (m > nums.size()) return -1;
        long long int low = *max_element(nums.begin(), nums.end());
        long long int high = accumulate(nums.begin(), nums.end(), 0LL);
        long long int ans = high;

        while(low<= high){
            long long int mid = low + (high - low)/2;
            if(ispossible(nums,m,mid)){
                ans = mid;
                high = mid -1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }
};