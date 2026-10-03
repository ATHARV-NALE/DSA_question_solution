/*You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. Each painter takes B units of time to paint 1 unit of board. You must assign boards to painters such that:

Each painter paints only contiguous segments of boards.
No board can be split between painters.
The goal is to minimize the time to paint all boards.
Return the minimum time required to paint all boards modulo 10000003.

Example 1:
Input: A = 2, B = 5, C = [1, 10]

Output: 50

Explanation:

Painter 1 paints board 0 (length = 1), time = 5
Painter 2 paints board 1 (length = 10), time = 50
Max time = 50
Return 50 % 10000003 = 50
Example 2:
Input: A = 10, B = 1, C = [1, 8, 11, 3]

Output: 11

Explanation:

Assign each board to a different painter
Max time = max(1, 8, 11, 3) = 11
Return 11 % 10000003 = 11*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class Solution{
    public:
    bool ispossible(int A, int B, vector<int>& C, int mid ){
        long long int painter = 1;
        long long int current_length = 0;
        for(int l : C){
            if( current_length + l <= mid){
                current_length += l;
            }
            else{painter++;
            current_length = l;
            if(l>mid){
                return false;
            }}
            
        }
        if(painter<= A){
            return true;
        }
        return false;
    }
    int paint(int A, int B, vector<int>& C){
      long long int  left = *max_element(C.begin(), C.end());
      long long int sum = 0;    
      for(int l : C){
        sum += l;
      }
      long long int right = sum;
      int t_time = -1;
      while(left<=right){
        int mid = left +(right-left)/2;
        if(ispossible(A,B,C,mid)){
            t_time = mid;
            right = mid -1;
        }
        else{
            left = mid +1;
        }
      }

      return (1LL*t_time * B) % 10000003;
    // bool isPossible(vector<int>& C , int A , long long int mid){
    //     long long int painterCount = 1;
    //     long long int boardSum = 0;
 
    //     for(int i = 0; i < C.size(); i++){
    //         if(boardSum + C[i] <= mid){
    //             boardSum += C[i];
    //         }
    //         else{
    //             painterCount ++;
 
    //             if(painterCount > A || C[i] > mid){
    //                 return false;
    //             }
 
    //             boardSum = C[i];
    //         }
    //     }
    //     return true;
    // }
 
    // int paint(int A, int B, vector<int>& C) {
 
    //     long long int start = 0;
 
    //     long long int sum = 0;
    //     for(int i = 0; i < C.size(); i++){
    //         sum += C[i];
    //     }
 
    //     long long int end = sum;
 
    //     long long int ans = -1;
 
    //     long long int mid = start + (end - start) / 2;
 
    //     while(start <= end){
    //         if(isPossible(C , A , mid)){
    //             ans = mid;
    //             end = mid - 1;
    //         }
    //         else{
    //             start = mid + 1;
    //         }
 
    //         mid = start + (end - start) / 2;
    //     }
    //     return (ans * B) % 10000003 ;
    }
};

