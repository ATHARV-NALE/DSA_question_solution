#include<bits/stdc++.h>

using namespace std;


class Solution{
    public:
    int check_power(long long mid, int m , int n){
        long long ans = 1;
        for(int i = 1; i<=m ; i++){
            ans*=mid;
            if(ans>n) return 2;
        }
        if(ans == n) return 1;
        return 0;

    }
    int find_nth_root(int m, int n){
        long long l = 1, r = n;
        while(l<= r){
            long long mid = l + (r-l)/2;
            int val = check_power(mid,m,n);
            if(val == 1){
                return mid;
            }
            else if(val == 0){
                l = mid +1;
            }
            else{
                r = mid -1;
            }
        }
        r   eturn -1;
    }
};