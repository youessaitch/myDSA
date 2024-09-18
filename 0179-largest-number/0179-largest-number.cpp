class Solution {
public:
    string largestNumber(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = i + 1;
    string ans = "";
    int flag = 0;

    if (n == 1) {
        return to_string(nums[0]);
    }
    
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] != nums[i + 1]) {
            flag = 1;
            break;
        }
    }
    
    if (flag == 0) {
        if (nums[0] == 0) {
            string res = "0";
            return res;
        } else {
            string res = "";
            for(int i=0;i<n;i++){
                res+= to_string(nums[i]);
            }
            return res;
        }
    }
    
    while (i < n) {
        while (j < n) {
            string r1 = to_string(nums[i]) + to_string(nums[j]);
            long long ij = stoll(r1);
            string r2 = to_string(nums[j]) + to_string(nums[i]);
            long long ji = stoll(r2);
            if (ji > ij) {
                swap(nums[i], nums[j]);
            }
            j++;
        }
        i++;
        j = i + 1;
    }
    
    for (int i = 0; i < n; i++) {
        ans += to_string(nums[i]);
    }
    
    return ans;
    }
};