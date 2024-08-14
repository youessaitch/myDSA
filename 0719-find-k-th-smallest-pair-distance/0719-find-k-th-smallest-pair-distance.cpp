class Solution {
public:
    int n;
    int smallestDistancePair(vector<int>& nums, int k) {
        n = nums.size();
        int maxi = *max_element(nums.begin(),nums.end());
        vector<int> v(maxi+1,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int num = abs(nums[i]-nums[j]);
                v[num]++;
            }
        }

        int t=k;
        for(int i=0;i<maxi+1;i++){
            t-=v[i];
            if(t<=0) return i;
        }
        return -1;
    }
};