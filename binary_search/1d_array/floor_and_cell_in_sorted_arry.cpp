#include<iostream>
#include<bits/stdc++.h>

using namespace std;


/**in this question we need to find the thing if x (target) is present in the  array then return
 direct the target value if target is not present in the array the find the value which greater than the vlaue which celling and the 
 smaller the value which is the floor
 **/ 
class Solution {
    public:


    //find the value the is the smaller than the target value knwon as floor 
    int find_floor(int arr[], int  n, int x){
        int low = 0;
        int high = n-1;
        int ans = -1;
        // what we do here is traves the array till low become high or greater than the high 
        while(low<=high){

            //find the mid value
            int mid = (low+high)/2;
            // here if check the mid if mid less than the target then 
            if(arr[mid] <= x){
                ans = arr[mid];
                low = mid + 1;
            }
            else{
            //if not found here then we will move the high pointer to mid -1
                high = mid -1;
            }

        }
       return ans;
    }

    int find_cell(int arr[], int n , int x){
        int low = 0;
        int high = n-1;

        int ans = -1;

        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]>=x){
                ans = arr[mid];
                high = mid -1;
          }
          else{
            low = mid+1;
          }
        }

        return ans;
    }

    pair<int, int> getflorr_cell(int arr[], int n, int x){
        int f = find_floor(arr,n,x);
        int c = find_cell(arr,n,x);
        return make_pair(f,c); 
    }

};