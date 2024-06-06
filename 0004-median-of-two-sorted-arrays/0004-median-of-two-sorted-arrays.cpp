class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> mp(n+m);
        for(int i=0;i<n;i++) mp[i]=nums1[i];
        for(int i=n;i<n+m;i++) mp[i]=nums2[i-n];

        sort(mp.begin(),mp.end());
        if((n+m)%2==1) return double(mp[(n+m)/2]);
        else{
            double ans = double(mp[(n+m)/2] + mp[(n+m)/2 - 1]);
            ans/=2;
            return ans; 
        }
        return 0;
    }
};