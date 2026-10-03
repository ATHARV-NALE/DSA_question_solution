/*You are given an array weights where weights[i] represents the weight of the i-th package on a conveyor belt. All the packages must be shipped in the order given from one port to another within days days.

Each day, the ship can carry a contiguous sequence of packages, as long as the total weight does not exceed its maximum capacity.

Your task is to find the minimum possible capacity of the ship so that all packages can be shipped within the given number of days.

Example 1:
Input: weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], days = 5

Output: 15

Explanation:

Minimum ship capacity = 15. One way to ship in 5 days:

Day 1: 1 + 2 + 3 + 4 + 5 = 15
Day 2: 6 + 7 = 13
Day 3: 8
Day 4: 9
Day 5: 10
No day exceeds capacity 15 and all packages are shipped in order in 5 days.

Example 2:
Input: weights = [3, 2, 2, 4, 1, 4], days = 3

Output: 6

Explanation:

One possible division with capacity 6:

Day 1: 3 + 2 = 5
Day 2: 2 + 4 = 6
Day 3: 1 + 4 = 5
All packages shipped in order within 3 days.*/


#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution {
    public:
    bool ispossible(vector<int>& weights, int days, int mid){
        int days_count = 1;
        int current_weight= 0;
        for(int w : weights){
            if(current_weight + w <= mid){
                current_weight+=w;
            }
            else{
            days_count++;   
            current_weight = w;
            }
        }
       
        if(days_count<= days){
            return true;
        }
        return false;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int count = 0;
        while(left<=right){
            int mid = left + (right -left) /2 ;
            if(ispossible(weights,days,mid)){
                count = mid;
                right = mid -1;
            }
            else{
                left = mid +1;
            }
        }
        return count;
    }     
};