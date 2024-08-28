#define ll long long
class Solution {
public:
    int n;

    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        n = nums.size();
        // 1 1 1 2
        // 1 -2 2
        ll ans = 0;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            v[i] = target[i]-nums[i];
        }

        for(int i=0;i<n;i++){
            int curr = v[i];
            int prev = (i==0)? 0 : v[i-1];
            
            // if diff sign then dont take them together
            if((curr<0 && prev>0) || (curr>0 && prev<0)){
                ans += abs(curr);
                continue;
            }

            // else take them together
            if(abs(curr)>abs(prev)) ans += abs(curr-prev);
            else if(curr<=prev) continue;
        }

        return ans;
    }
};