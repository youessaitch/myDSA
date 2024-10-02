class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i],0,i}); //arr,rank,index
        }

        sort(v.begin(),v.end());

        int rank = 1;

        for(int i=0;i<n;i++){
            if(i>0 && v[i][0]==v[i-1][0]){
                v[i][1] = v[i-1][1];
            }
            else{
                v[i][1] = rank;
                rank++;
            }
        }

        vector<int> ans;

        auto lambda = [](const vector<int> &a,const vector<int> &b){
            return a[2]<b[2];
        };

        sort(v.begin(),v.end(),lambda);

        for(int i=0;i<n;i++){
            ans.push_back(v[i][1]);
        }

        return ans;
    }
};