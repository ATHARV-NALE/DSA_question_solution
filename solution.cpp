#include <iostream>
#include <bits/stdc++.h>
#include "Sliding_windows-two_pointers\maxConsecutiveOnesthree.cpp"
using namespace std;


int main(){
    Solution s;


    int t;              
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int A ;
        cin >> A;
       
          

        vector<int> nums(n);    

        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        
        int ans = s.maxones(nums,A);

        cout << ans << endl;
    }
    // int ans = s.find_nth_root(m,n); // Ensure this matches your class method name
    // cout << ans << endl;
    return 0;
} 