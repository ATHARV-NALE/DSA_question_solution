#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    int first_count(vector<int>& arr, int x , int n ){
        int left = 0;
        int right = n-1;

        int first = -1;

        while(left<=right){
            int mid = (left + right)/2;

            if(arr[mid] ==x){
                first = mid;
                right = mid -1;
            }
            else if(arr[mid] < x){
                left = mid +1;
            }
            else{
                right = mid -1; 
            }
        }
        return first;
    }

    int second_count(vector<int>& arr, int x , int n ){
        int left = 0;
        int right = n-1;

        int second = -1;

        while(left<=right){
            int mid = (left + right)/2;

            if(arr[mid] ==x){
                second = mid;
                left = mid +1;
            }
            else if(arr[mid] < x){
                left = mid +1;
            }
            else{
                right = mid -1; 
            }
        }
        return second;
    }
    pair<int,int> firstandsecond(vector<int>& arr , int x , int n){
        int first = first_count(arr,x,n);
        if(first == -1) return {-1,-1};
        int second = second_count(arr,x,n);
              return {first, second};
    }
    int count(vector<int>& arr, int x, int n){
        pair<int,int> ans = firstandsecond(arr,x,n);
        if(ans.first == -1) return 0;
        return(ans.second - ans.first +1);
    }
};