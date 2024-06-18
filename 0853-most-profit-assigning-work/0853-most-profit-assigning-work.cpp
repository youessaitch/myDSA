class Solution {
    #define pi pair<int,int>
private:
    struct compare{
        bool operator()(const pi &a, const pi &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first<b.first;
        }
    };

public:

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end(),compare());
        sort(worker.begin(),worker.end());

        for(int i=0;i<n;i++){
            cout<<v[i].first<<" "<<v[i].second<<endl;
        }

        int ans = 0;
        int j=0;
        int maxProfit = 0;
        for(int i=0;i<worker.size();i++){
            while(j < n && v[j].first <= worker[i]) {
                maxProfit = max(maxProfit, v[j].second);
                j++;
            }
            ans += maxProfit;
        }
        return ans;

    }
};