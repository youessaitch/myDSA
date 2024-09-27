class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // map was nlogn
        // deque will be O(n)
        // monotonic deque
        deque<int> dq;
        vector<int> ans;

        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        for(int i=k;i<nums.size();i++){
            //out of bound remove
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);

            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};