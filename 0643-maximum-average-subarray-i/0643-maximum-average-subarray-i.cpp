class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int t= k;
        double window = 0;
        int cnt = 0;
        while(cnt!=t){
            window += 1.0*nums[cnt];
            cnt++;
        }

        window/=k;
        double ans = window;
        int i=0;
        int j=k;
        while(j<n){
            window -= 1.0*(nums[i])/k; 
            window += 1.0*(nums[j])/k;
            ans = max(ans,window);
            i++;
            j++;
        }
        return ans;
    }
};