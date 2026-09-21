#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int find_rotation(vector<int>& arr, int n){
        int left = 0;
        int right = n-1;

        while(left < right){
            int mid = left + (right - left) / 2;
            if(arr[mid] > arr[right]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};