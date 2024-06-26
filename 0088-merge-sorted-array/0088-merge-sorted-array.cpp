class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i=0,j=0;
        while(i<m && j<n){
            if(nums2[j]<nums1[i]){
                ans.push_back(nums2[j]);
                j++;
            }else{
                ans.push_back(nums1[i]);
                i++;
            }
        }

        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }

        for(int k=0;k<m+n;k++){
            nums1[k] = ans[k];
        }
    }
};