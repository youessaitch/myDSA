class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=0,r=0;
        int n = cardPoints.size();
        if(n<k) return 0;
        vector<int> pref;
        int temp =0;
        for(int i=0;i<n;i++){
            temp+=cardPoints[i];
            pref.push_back(temp);
        }
        int t = n - k;
        if(t==0) return temp;
        // return t;
        l=0;
        r=t-1;
        // return pref[n-1]-pref[0];
        int maxi = -1e6;
        int sum = 0;
        while(r<n){
            sum = pref[n-1];
            sum -= pref[r];
            if(l>0){
                sum+=pref[l-1];
            }
            maxi = max(maxi,sum);
            l++;
            r++;
        }
        return maxi;
    }
};