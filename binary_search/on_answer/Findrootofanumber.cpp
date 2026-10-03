#include<bits/stdc++.h>

using namespace std;



class solution{
    public:
    int floorSqrt(int n){
        if (n == 0 || n ==1) return n;
        long long l=1, r = n, ans = 0;

        while(l<= r){
            long long mid = l + (r-l)/2;
            if(mid * mid  <= n){
                ans = mid;
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
        return ans;
    }

};