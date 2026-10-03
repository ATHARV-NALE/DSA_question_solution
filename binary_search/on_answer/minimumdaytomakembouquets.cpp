#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*Given n roses and an array nums where nums[i] denotes that the 'ith' rose will 
bloom on the nums[i]th day, only adjacent bloomed roses can be picked to make a 
bouquet. Exactly k adjacent bloomed roses are required to make a single bouquet. 
Find the minimum number of days required to make at least m bouquets, each containing 
k roses. Return -1 if it is not possible.

Example 1:
Input: n = 8, nums = [7, 7, 7, 7, 13, 11, 12, 7], m = 2, k = 3

Output: 12

Explanation: On the 12th the first 4 flowers and the last 3 flowers would have already 
bloomed. So, we can easily make 2 bouquets, one with the first 3 and another with the last 3 flowers.

Example 2:
Input: n = 5, nums = [1, 10, 3, 10, 2], m = 3, k = 2

Output: -1

Explanation: If we want to make 3 bouquets of 2 flowers each, we need at least 6 
flowers. But we are given only 5 flowers, so, we cannot make the bouquets.*/
class Solution{
    public:
    bool possible(int n,vector<int>nums, int k, int m , int mid ){
        int consecutive_bloomed = 0 , bouquets = 0;

        for(int i =0; i<n ; i++){
            if(nums[i] > mid){
                consecutive_bloomed = 0;
                continue;
            }
            ++consecutive_bloomed;
            if(consecutive_bloomed == k){
                bouquets++;
                consecutive_bloomed = 0;}
            if(bouquets == m){
                return true;
            }
        }
        return false;
    }
    int roseGarden(int n,vector<int> nums, int k, int m) {
        if(1ll *m*k > nums.size()){
            return -1;
        }
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int answer = -1;

        while(left <= right){
            int mid = left+(right-left)/2;

            if(possible(n,nums,k,m,mid)){
                answer = mid;
                right = mid -1;

            }
            else{
                left = mid +1;
            }
        }
        return answer;
  }
};
