#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution{
    public:
    bool find_ceil(vector<int>& nums, int mid, int h){
        int val  = 0;
        for(int hour: nums){
           val += (hour + mid -1) / mid ;
        }
        if (val> h) return false;

        return val <=h;
    }
    int findk(vector<int>& nums, int h){
        int left = 1;
        int right = *max_element(nums.begin(),nums.end());
        int  k  = 0;

        while(left<right){
            int mid = left + (right-left) /2;
            if(find_ceil(nums,mid,h) ){
                right = mid;
            }else{
                left = mid +1;
            }

        }
        return left;
    }
};