#include <iostream>
#include <bits/stdc++.h>
#include "binary_search\1d_array\Findouthowmanytimesthearrayhasbeenrotated.cpp"
using namespace std;


int main(){
    Solution s;

    int t;              
    cin >> t;

    while(t--){
        int n ;
        
        cin >> n ;  

        vector<int> arr(n);    
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
       
        int ans = s.find_rotation(arr,n);

        cout << ans << endl;
    }

    return 0;
} 