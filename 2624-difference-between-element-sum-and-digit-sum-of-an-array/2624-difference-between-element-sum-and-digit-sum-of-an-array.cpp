#include <bits/stdc++.h>
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int digitSum=0;
        for(auto it: nums){
            string t = to_string(it);
            // if(t.size()==1) digitSum += it;
            // else{
            for(auto &jt:t){
                digitSum += (jt-'0');
            }
            // }
            
        }
        return abs(sum-digitSum);
    }
};