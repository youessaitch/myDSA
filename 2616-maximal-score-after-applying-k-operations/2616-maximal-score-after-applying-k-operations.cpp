class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for(auto it: nums) pq.push(it);

        long long ans = 0;

        while(k--){
            long long top = pq.top();
            pq.pop();
            cout<<top<<" ";
            ans += top;
            long long temp = ceil((double)top/3);
            pq.push(temp);
        }

        return ans;
    }
};