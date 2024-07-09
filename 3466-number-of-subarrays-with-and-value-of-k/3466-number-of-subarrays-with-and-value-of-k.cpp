class Solution {
public:
    int n;
    
    int calc(vector<int>& bits, int w) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (bits[i] == w) {
                ans += (1 << i);
            }
        }
        return ans;
    }

    long long atLeastK(vector<int>& nums, int k) {
        int l = 0, r = 0;
        long long ans = 0;
        vector<int> bits(32, 0);
        while (r < n) {
            for (int i = 0; i < 32; i++) {
                if (nums[r] & (1 << i)) {
                    bits[i]++;
                }
            }

            while (r - l + 1 > 0 && calc(bits, r - l + 1) < k) {
                for (int i = 0; i < 32; i++) {
                    if (nums[l] & (1 << i)) {
                        bits[i]--;
                    }
                }
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }

    long long countSubarrays(vector<int>& nums, int k) {
        n = nums.size();
        return atLeastK(nums, k) - atLeastK(nums, k + 1);
    }
};
