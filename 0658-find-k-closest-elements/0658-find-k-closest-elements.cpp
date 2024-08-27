class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> ans;
        vector<int> v(n);
        int mini = INT_MAX;
        int idx = -1;

        for(int i=0;i<n;i++){
            v[i] = abs(arr[i]-x);
            if(v[i]<mini){
                mini = v[i];
                idx = i;
            }
        }
        ans.push_back(arr[idx]);

        k--;
        int i=idx-1;
        int j=idx+1;
        while(k>0){
            if(i>=0 && j<n){
                if(v[i]<v[j]){
                    ans.push_back(arr[i]);
                    i--;
                    k--;
                }else if(v[i]>v[j]){
                    ans.push_back(arr[j]);
                    j++;
                    k--;
                } else{
                    ans.push_back(arr[i]);
                    i--;
                    k--;
                }
            }

            else if(i>=0 && j>=n){
                for(int p=i;p>=0;p--){
                    ans.push_back(arr[p]);
                    k--;
                    if(k==0) break;
                }
            }else if(i<0 && j<n){
                for(int p=j;p<n;p++){
                    ans.push_back(arr[p]);
                    k--;
                    if(k==0) break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};