class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        multimap<int,int> mpp;

        int i=0,j=0;

        while(j<n){
            mpp.insert({nums[j],1});

            if(j-i+1 > k){
                if(mpp.find(nums[i])!=mpp.end()) mpp.erase(mpp.find(nums[i])); //delete only one occurence
                i++;
            }

            if(j-i+1 == k){
                ans.push_back(mpp.rbegin()->first);
            }

            j++;
        }

        return ans;
    }   
};

//          // map was nlogn
//         // deque will be O(n)
//         // monotonic deque
//         deque<int> dq;
//         vector<int> ans;

//         for(int i=0;i<k;i++){
//             //aage wale chote hai not needed so remove ( monotonic )
//             while(!dq.empty() && nums[i]>=nums[dq.back()]){
//                 dq.pop_back();
//             }
//             dq.push_back(i);
//         }

//         ans.push_back(nums[dq.front()]);

//         for(int i=k;i<nums.size();i++){
//             //out of bound remove
//             while(!dq.empty() && dq.front() <= i-k){
//                 dq.pop_front();
//             }
            
//             //aage wale chote hai not needed so remove ( monotonic )
//             while(!dq.empty() && nums[i]>=nums[dq.back()]){
//                 dq.pop_back();
//             }
//             dq.push_back(i);

//             ans.push_back(nums[dq.front()]);
//         }

//         return ans;