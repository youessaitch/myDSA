class Solution {
public:
    int moo(int mid, vector<int> &arr, int n, int k){
        int cnt = 0; 
        int sum = 0;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }else{
                sum = arr[i];
                cnt++;
            }
        }
        if(sum<=mid) cnt++;
        return cnt;
    }

    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return -1;
        int lo = *max_element(arr.begin(),arr.end());
        int hi = 0;
        for(auto it: arr) hi+=it;
        int ans = -1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int ch = moo(mid,arr,n,k);
            if(ch<=k){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
    }
};