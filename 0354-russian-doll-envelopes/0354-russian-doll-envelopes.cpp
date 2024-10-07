class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        auto lambda = [](const vector<int> &a, const vector<int> &b){
            if(a[0]!=b[0]) return a[0]<b[0];
            else return a[1]>b[1];
        };

        sort(envelopes.begin(),envelopes.end(),lambda);

        for(int i=0;i<n;i++){
            cout<<"["<<envelopes[i][0]<<","<<envelopes[i][1]<<"]"<<" ";
        }

        int ans = 1;

        vector<int> res;
        int currW = envelopes[0][0];
        int currH = envelopes[0][1];
        res.push_back(currH);

        for(int i=1;i<n;i++){
            if(envelopes[i][1] > res[res.size()-1]) res.push_back(envelopes[i][1]);
            else{
                //find index of just bada element in ans
                auto idx = lower_bound(res.begin(),res.end(),envelopes[i][1])-res.begin();
                res[idx] = envelopes[i][1];
            }
        }

        ans = res.size();
        return ans;
    }
};