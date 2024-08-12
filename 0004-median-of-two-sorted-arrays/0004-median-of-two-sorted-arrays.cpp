class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n==0){
            if(m%2==1) return 1.0*nums2[m/2];
            else return 1.0*(nums2[m/2]+nums2[m/2-1])/2.0;
        }

        if(m==0){
            if(n%2==1) return 1.0*nums1[n/2];
            else return 1.0*(nums1[n/2]+nums1[n/2-1])/2.0;
        }

        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int lo=0, hi=n;
        while(lo<=hi){
            int mid1 = (lo+hi)/2;
            int mid2 = (n+m+1)/2 - mid1;

            int l1=INT_MIN, l2=INT_MIN;
            int r1=INT_MAX, r2=INT_MAX;

            if(mid1<n) r1 = nums1[mid1];
            if(mid2<m) r2 = nums2[mid2];
            if(mid1-1>=0) l1 = nums1[mid1-1];
            if(mid2-1>=0) l2 = nums2[mid2-1];

            if(l1<=r2 && l2<=r1){
                if((n+m)%2==0)
                    return 1.0*(max(l1,l2) + min(r1,r2))/2.0;
                else return 1.0*max(l1,l2);
            }else if(l1 > r2) hi=mid1-1;
            else lo = mid1+1;
        }
        return 0.0;
    }
};