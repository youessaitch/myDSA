class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int prev = -200;
        for(int j=0;j<n;j++){
            if(nums[j]!=prev){
                nums[i]=nums[j];
                prev = nums[i];
                i++;
            }
        }
        return i;
    }
};