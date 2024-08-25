class Solution {
public:
    vector<int> baanto(int n) {
        vector<int> v;
        while(n > 0) {
            v.push_back(n % 10);
            n /= 10;
        }
        while(v.size() != 7) v.push_back(0);
        return v;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            vector<int> d1 = baanto(nums[i]);
            // for(int p=0;p<d1.size();p++) cout<<d1[p]<<" ";
            // cout<<endl;

            for(int j = i + 1; j < n; j++) {
                vector<int> d2 = baanto(nums[j]);
                // for(int p=0;p<d1.size();p++) cout<<d2[p]<<" ";
                // cout<<endl;
                
                int s1 = -1, s2 = -1, cnt = 0;
                for(int k = 0; k < 7; k++) {
                    if(d1[k] != d2[k]) {
                        cnt++;
                        if(s1 == -1) s1 = k;
                        else if(s2 == -1) s2 = k;
                    }
                }

                if(s1 != -1 && s2 != -1) swap(d2[s1], d2[s2]);
                if(cnt == 0 || (cnt == 2 && d1 == d2)) ans++;
            }
        }
        return ans;
    }
};
