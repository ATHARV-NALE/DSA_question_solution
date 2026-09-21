#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set> 
using namespace std;   

class Solution {
public:     

int longestSubstringwithoutRepetition(string s) {
        int l = 0;
        int max_length = 0 ; 

        unordered_set<char> string;
        for(int i = 0; i< s.length(); i++){
            while(string.find(s[i]) != string.end()){
                //eliminate the term 
                string.erase(s[l]);
                l++;
                // improve the l by 1
            }

            string.insert(s[i]);
            max_length = max(max_length, i-l +1);
        }
        return max_length;
}
};