class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1;
        int i = 1; //starting from 1

        for(int j=1;j<n;j++){

            if(nums[j]==nums[j-1]){
                cnt++;
            }else cnt = 1;

            if(cnt<=2){
                nums[i] = nums[j];
                i++;
            }
            
        }

        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        return i;
    }
};