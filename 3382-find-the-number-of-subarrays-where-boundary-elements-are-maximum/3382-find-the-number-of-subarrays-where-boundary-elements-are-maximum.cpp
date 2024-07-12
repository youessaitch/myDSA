class Solution {
public:
    int n;
    long long numberOfSubarrays(vector<int>& nums) {
        n = nums.size();
        vector<int> nge(n,n); //storing next greater element index
        stack<int> st; //stack
        for(int i=n-1;i>=0;i--){ 
            while(st.empty() == false && nums[i] >= nums[st.top()]) st.pop();
            if(st.empty() == false) nge[i] = st.top();
            st.push(i);
        }

        // for(int i=0;i<n;i++) cout<<nge[i]<<" ";
        long long ans = 0;
        map<int,vector<int>> mpp;
        for(int i=0;i<n;i++) mpp[nums[i]].push_back(i);

        for(int i=0;i<n;i++){
            int L = i, R = nge[i]-1;
            int x = lower_bound(mpp[nums[i]].begin(),mpp[nums[i]].end(),L) - mpp[nums[i]].begin(); //first occurence of nums[i] that is not less than L
            int y = upper_bound(mpp[nums[i]].begin(),mpp[nums[i]].end(),R) - mpp[nums[i]].begin(); //first occurence of nums[i] that is greater than R
            ans += y-x;
        }

        return ans;
    }
};