class Solution {
public:
    int n;

    //Similar to Russian Doll Problem
    int maxPathLength(vector<vector<int>>& v, int k) {
        n = v.size();

        int reqx = v[k][0];
        int reqy = v[k][1];

        auto lambda = [](const vector<int> &a, const vector<int> &b){
            if(a[0]!=b[0]) return a[0]<b[0];
            else return a[1]>b[1];
        };

        sort(v.begin(),v.end(),lambda);

        for(int i=0;i<n;i++){
            cout<<"["<<v[i][0]<<","<<v[i][1]<<"]"<<" ";
        }
        cout<<endl;

        int ans = 1;

        vector<int> left, right; //left of required coordinate and right of req coordinate

        for(auto it: v){
            int x = it[0];
            int y = it[1];

            if(x<reqx && y<reqy) left.push_back(y);
            if(x>reqx && y>reqy) right.push_back(y);
        }

        vector<int> resLeft;

        for(int i=0;i<left.size();i++){
            if(i==0) {resLeft.push_back(left[0]);continue;}
            if(left[i] > resLeft[resLeft.size()-1]) resLeft.push_back(left[i]);
            else{
                //find index of just bada element in resLeft
                auto idx = lower_bound(resLeft.begin(),resLeft.end(),left[i])-resLeft.begin();
                resLeft[idx] = left[i];
            }
        }

        vector<int> resRight;

        for(int i=0;i<right.size();i++){
            if(i==0) {resRight.push_back(right[0]);continue;}
            if(right[i] > resRight[resRight.size()-1]) resRight.push_back(right[i]);
            else{
                //find index of just bada element in resLeft
                auto idx = lower_bound(resRight.begin(),resRight.end(),right[i])-resRight.begin();
                resRight[idx] = right[i];
            }
        }

        for(int i=0;i<resLeft.size();i++){
            cout<<resLeft[i]<<" ";
        }
        cout<<endl;

        for(int i=0;i<resRight.size();i++){
            cout<<resRight[i]<<" ";
        }
        cout<<endl;

        ans = resLeft.size() + resRight.size() + 1; //one for the point we need to have in our answer
        return ans;
    }
};
